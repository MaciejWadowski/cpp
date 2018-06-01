//
// Created by wadziuxxx on 5/31/18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <experimental/optional>

namespace academia{

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *) = 0;
        virtual void Serialize(Serializer *)const = 0;
    };

    class Serializer {
    public:
        Serializer();
        explicit Serializer(std::ostream*);
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;

        std::ostream *out;
    };


    class Room : public Serializable{
    public:
        Room();
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id,std::string,Type);
        ~Room() = default;
        void Serialize(Serializer *) override ;
        void Serialize(Serializer *)const override;
        std::string EnumToString()const;
        int Id();
    private:
        int id;
        std::string name;
        Type type;
    };

    class Building : public Serializable{
    public:
        Building() = default;
        Building(int, std::string, std::initializer_list<Room> );
        void Serialize(Serializer *) override;
        void Serialize(Serializer *)const override;
        std::vector<std::reference_wrapper<const Serializable>> VectorToReferenceWrapper()const;
        int Id()const;
    private:
        int id;
        std::string name;
        std::vector<Room> rooms;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer() : Serializer(){};
        explicit JsonSerializer(std::ostream*out) : Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value)override ;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class XmlSerializer : public Serializer{
    public:
        explicit XmlSerializer(std::ostream *out) : Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value)override ;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class BuildingRepository{
    public:
        BuildingRepository();
        ~BuildingRepository() = default;
        BuildingRepository(std::initializer_list<Building>);
        void Add(const Building&);
        void StoreAll(Serializer*)const;
        std::experimental::optional<Building> operator[](int)const;
    private:
        std::vector<Building> building;
    };

}


#endif //JIMP_EXERCISES_SERIALIZATION_H
