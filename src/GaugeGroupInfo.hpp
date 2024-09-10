#pragma once
#include <Grid/Grid.h>
#include <string>

// Useful typedefs
template<typename Representation>
using Impl = Grid::WilsonImpl<Grid::vComplexD, Representation, Grid::CoeffReal>;

template<typename Representation>
using GaugeField = typename Impl<Representation>::Field;

enum class GroupName
{
  SU,
  Sp
};

// Logic to resolve a Group + Representation to a concrete Grid Type.
enum class RepresentationName
{
  Fundamental,
  Adjoint,
  TwoIndexSymmetric,
  TwoIndexAntiSymmetric
};

template<typename T>
struct type_identity
{
    typedef T type;
};

template<typename GroupName, int Nc, RepresentationName repname>
constexpr auto getRepresentation()
{
  using namespace Grid;

  if constexpr (repname == RepresentationName::Fundamental)
    return type_identity<FundamentalRep<Nc, GroupName>>{};
  else if constexpr(repname == RepresentationName::Adjoint)
    return type_identity<AdjointRep<Nc>>{};
  else if constexpr(repname == RepresentationName::TwoIndexSymmetric)
    return type_identity<TwoIndexRep<Nc, TwoIndexSymmetry::Symmetric, GroupName>>{};
  else if constexpr(repname == RepresentationName::TwoIndexAntiSymmetric)
    return type_identity<TwoIndexRep<Nc, TwoIndexSymmetry::AntiSymmetric, GroupName>>{};
}

template<typename GroupName, int Nc, RepresentationName repname>
constexpr auto getConfigGroup()
{
  using namespace Grid;

  if constexpr (repname == RepresentationName::Fundamental)
    return type_identity<GaugeGroup<Nc, GroupName>>{};
  else if constexpr(repname == RepresentationName::Adjoint)
    return type_identity<SU_Adjoint<Nc>>{};
  else if constexpr(repname == RepresentationName::TwoIndexSymmetric)
    return type_identity<GaugeGroupTwoIndex<Nc, TwoIndexSymmetry::Symmetric, GroupName>>{};
  else if constexpr(repname == RepresentationName::TwoIndexAntiSymmetric)
    return type_identity<GaugeGroupTwoIndex<Nc, TwoIndexSymmetry::AntiSymmetric, GroupName>>{};
}


struct GroupInfo
{
    std::string group;
    int Nc;
    std::string representation;
    
    GroupInfo() {}
    GroupInfo(const std::string& group, int Nc, const std::string& representation) 
    {
      this->group          = group;
      this->Nc             = Nc;
      this->representation = representation;
    }


    bool operator==(const GroupInfo& other) const
    {
        return (this->group==other.group) && (this->Nc==other.Nc) && (this->representation==other.representation);
    }

    std::string tag() const
    {
        return this->group + "(" + std::to_string(this->Nc) + "), " + this->representation;
    }
};
