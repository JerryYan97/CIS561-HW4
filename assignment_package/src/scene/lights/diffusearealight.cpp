#include "diffusearealight.h"

Color3f DiffuseAreaLight::L(const Intersection &isect, const Vector3f &w) const
{
    //TODO
    // return Color3f(0.f);
    return glm::dot(isect.normalGeometric, w) > 0.f ? emittedLight : Color3f(0.f);
}
