#include "TH.h"
#include "luaT.h"

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_string_(NAME) TH_CONCAT_STRING_3(torch., Real, NAME)
#define nn_(NAME) TH_CONCAT_3(nn_, Real, NAME)

static const void* torch_FloatTensor_id = NULL;
static const void* torch_DoubleTensor_id = NULL;

#include "generic/HardTanh.c"
#include "THGenerateFloatTypes.h"

#include "generic/Exp.c"
#include "THGenerateFloatTypes.h"

#include "generic/LogSigmoid.c"
#include "THGenerateFloatTypes.h"

#include "generic/LogSoftmax.c"
#include "THGenerateFloatTypes.h"

#include "generic/Sigmoid.c"
#include "THGenerateFloatTypes.h"

#include "generic/SoftPlus.c"
#include "THGenerateFloatTypes.h"

#include "generic/Tanh.c"
#include "THGenerateFloatTypes.h"

#include "generic/SoftMax.c"
#include "THGenerateFloatTypes.h"

#include "generic/Max.c"
#include "THGenerateFloatTypes.h"

#include "generic/Min.c"
#include "THGenerateFloatTypes.h"

#include "generic/MSECriterion.c"
#include "THGenerateFloatTypes.h"

#include "generic/AbsCriterion.c"
#include "THGenerateFloatTypes.h"

DLL_EXPORT int luaopen_libnn(lua_State *L)
{
  torch_FloatTensor_id = luaT_checktypename2id(L, "torch.FloatTensor");
  torch_DoubleTensor_id = luaT_checktypename2id(L, "torch.DoubleTensor");

  lua_newtable(L);
  lua_pushvalue(L, -1);
  lua_setfield(L, LUA_GLOBALSINDEX, "nn");

  nn_FloatMin_init(L);
  nn_FloatMax_init(L);
  nn_FloatExp_init(L);
  nn_FloatHardTanh_init(L);
  nn_FloatLogSoftMax_init(L);
  nn_FloatMSECriterion_init(L);
  nn_FloatAbsCriterion_init(L);
  nn_FloatLogSigmoid_init(L);
  nn_FloatSigmoid_init(L);
  nn_FloatSoftMax_init(L);
  nn_FloatSoftPlus_init(L);
  nn_FloatTanh_init(L);

  nn_DoubleMin_init(L);
  nn_DoubleMax_init(L);
  nn_DoubleExp_init(L);
  nn_DoubleHardTanh_init(L);
  nn_DoubleLogSoftMax_init(L);
  nn_DoubleMSECriterion_init(L);
  nn_DoubleAbsCriterion_init(L);
  nn_DoubleLogSigmoid_init(L);
  nn_DoubleSigmoid_init(L);
  nn_DoubleSoftMax_init(L);
  nn_DoubleSoftPlus_init(L);
  nn_DoubleTanh_init(L);

/*  

  nn_SpatialConvolution_init(L);
  nn_SpatialSubSampling_init(L);
  nn_TemporalConvolution_init(L);
  nn_TemporalSubSampling_init(L);
  nn_SparseLinear_init(L);
*/

  return 1;
}
