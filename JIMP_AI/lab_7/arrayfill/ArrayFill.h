//
// Created by wadziuxxx on 5/1/18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <iostream>
#include <vector>
#include <random>
#include <memory>

namespace arrays{
    class ArrayFill{
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill: public ArrayFill{
    public:

        UniformFill();

        explicit UniformFill(int value);

        virtual int Value(int index) const override ;

    private:
        int value;
    };

    class IncrementalFill : public ArrayFill{
    public:

        IncrementalFill(int value_);

        explicit IncrementalFill(int value_, int inc_);

        virtual int Value(int index) const override;

    private:
        int value;
        int incrementation;
    };
    
    class SquaredFill : public ArrayFill{
    public:
        
        SquaredFill();
        
        SquaredFill(int a_);
        
        SquaredFill(int a_,int b_);

        virtual int Value(int index) const override ;

    private:    
        int a;
        int b;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
