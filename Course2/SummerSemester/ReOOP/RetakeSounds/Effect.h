//
// Created by Sybatron on 8/15/2023.
//

#ifndef RETAKE_SOUNDS_EFFECT_H
#define RETAKE_SOUNDS_EFFECT_H

#pragma once

#include "Sound.h"

template<typename SampleType>
class Functor {
public:
    virtual SampleType operator()(SampleType sample, size_t index) const {
        return 0;
    };
};

template<typename SampleType, typename PolicyFunctor = Functor<SampleType> *>
struct TransformFunc {
    PolicyFunctor functor;

    TransformFunc(PolicyFunctor functor = PolicyFunctor()) : functor(functor) {}

    SampleType operator()(SampleType sample, size_t index) const {
        return (*functor)(sample, index);
    }
};


template<typename SampleType, typename EffectFunctor=Functor<SampleType>>
class Effect : public Sound<SampleType> {
public:
//    using EffectLambdaType = SampleType(*)(SampleType sample, size_t index);

    Effect(const Sound<SampleType> *sound,
           TransformFunc<SampleType,
                   EffectFunctor *> transformFunc
           = TransformFunc<SampleType, EffectFunctor>(), unsigned int boundary = 1);

//    Effect(const Sound<SampleType> *sound, EffectLambdaType transformFunc);

    Sound<SampleType> *clone() const override;

};


#include "Effect.inl"

#endif //RETAKE_SOUNDS_EFFECT_H
