//
// Created by wadziuxxx on 5/31/18.
//

#include <functional>
#include "Serialization.h"

academia::Serializer::Serializer(std::ostream *stream) {
    out = stream;
}

academia::Serializer::Serializer() {
    *out << "";
}

academia::Room::Room(int a, std::string b, academia::Room::Type c) {
    id = a;
    name = b;
    type = c;
}

void academia::Room::Serialize(academia::Serializer *x) {
    x->Header("room");
    x->IntegerField("id",id);
    x->StringField("name",name);
    x->StringField("type",EnumToString());
    x->Footer("room");
}

academia::Room::Room() {
    id = 0;
    name = "";

}

std::string academia::Room::EnumToString()const {
    switch(type){
        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
}

void academia::Room::Serialize(academia::Serializer *x) const {
    x->Header("room");
    x->IntegerField("id",id);
    x->StringField("name",name);
    x->StringField("type",EnumToString());
    x->Footer("room");
}

int academia::Room::Id() {
    return id;
}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    *out << "\"" << field_name << "\": " << value << ", ";
}

void academia::JsonSerializer::Header(const std::string &object_name) {
    *out << "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *out << "}";
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    *out << "\"" << field_name << ": " << value << ", ";
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    *out << "\"" << field_name << "\": \"" << value << "\"";
    if(value != "COMPUTER_LAB" and value != "CLASSROOM" and value != "LECTURE_HALL")
    *out << ", ";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    *out << "\"" << field_name << "\": " << value << ", ";
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,

                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *out << "\"" << field_name << "\": [";
    int curr = 0;
    for(auto i : value){
        SerializableField(field_name,i);
        curr++;
        if(curr < value.size())
            *out << ", ";
    }
    *out << "]";
}


academia::Building::Building(int a , std::string b , std::initializer_list<academia::Room> list) {
    id = a;
    name = b;
    for(auto i: list)
        rooms.push_back(i);
}

void academia::Building::Serialize(academia::Serializer *x) {
    x->Header("building");
    x->IntegerField("id",id);
    x->StringField("name",name);
    x->ArrayField("rooms",VectorToReferenceWrapper());
    x->Footer("building");
}

void academia::Building::Serialize(academia::Serializer *x) const {
    x->Header("building");
    x->IntegerField("id",id);
    x->StringField("name",name);
    x->ArrayField("rooms",VectorToReferenceWrapper());
    x->Footer("building");
}

std::vector<std::reference_wrapper<const academia::Serializable>> academia::Building::VectorToReferenceWrapper() const {
    std::vector<std::reference_wrapper<const academia::Serializable>> output;
    for(auto &i : rooms)
        output.emplace_back(std::cref(i));
    return output;
}

int academia::Building::Id() const {
    return id;
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    *out << '<' << object_name << '>';
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    *out << "<\\" << object_name << '>';
}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    *out << '<' << field_name << '>' << value << "<\\" << field_name << '>';
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    *out << '<' << field_name << '>' << value << "<\\" << field_name << '>';
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *out << '<' << field_name << '>' << value << "<\\" << field_name << '>';
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    *out << '<' << field_name << '>' << value << "<\\" << field_name << '>';
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *out << '<' << field_name << '>';

    for(auto i : value)
        SerializableField(field_name,i);


    *out << "<\\" << field_name << '>';
}

academia::BuildingRepository::BuildingRepository(std::initializer_list<academia::Building> buildings_) {
    for(auto i : buildings_)
        building.emplace_back(i);
}

void academia::BuildingRepository::Add(const academia::Building &val) {
    building.emplace_back(val);
}

void academia::BuildingRepository::StoreAll(academia::Serializer *x) const {
    std::vector<std::reference_wrapper<const Serializable>> buildings_(building.begin(),building.end());
    x->Header("building_repository");
    x->ArrayField("buildings",buildings_);
    x->Footer("building_repository");
}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int x) const {
    for(auto i : building) {
        if (i.Id() == x)
            return i;
    }
}

academia::BuildingRepository::BuildingRepository() {
    building = {};
}
