#ifndef NEG_TWO_LL_SUM_HH
#define NEG_TWO_LL_SUM_HH

#include <vector>

#include "Mint/Minimisable.h"

namespace MINT
{
  class IMinimisable;
  class MinuitParameterSet;

  class Neg2LLSum : public Minimisable
  {
   public:
    Neg2LLSum( MinuitParameterSet* mps=0 );

    template<typename IMINIMISIBLE>
    Neg2LLSum( MinuitParameterSet* mps, IMINIMISIBLE* ll )
      : Minimisable(mps)
    { insert(ll); }

    template<typename IMINIMISIBLE_FIRST, typename... IMINIMISIBLE_REST>
    Neg2LLSum( MinuitParameterSet* mps,
	       IMINIMISIBLE_FIRST* ll_first, IMINIMISIBLE_REST*... ll_rest )
      : Neg2LLSum(mps, ll_rest...)
    { insert(ll_first); }

    Neg2LLSum( const std::vector<IMinimisable*>& likList_in,
	       MinuitParameterSet* mps=0 );

    Neg2LLSum( const Neg2LLSum& other );

    bool add( IMinimisable* llPtr );
    bool insert( IMinimisable* llPtr );

    virtual void beginFit();

    virtual void parametersChanged();

    virtual void endFit();

    double getVal();

    bool addConstraints();

    virtual std::vector<double> Gradient( const std::vector<double>& par );

    virtual bool useAnalyticGradient();

    virtual void setUseAnalyticGradient( bool useAnalyticGradient );

   private:
    std::vector<IMinimisable*> _likList;
  };
} //namespace MINT

#endif //NEG_TWO_LL_SUM_HH
