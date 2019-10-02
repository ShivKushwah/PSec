file(REMOVE_RECURSE
  "enclave_u.c"
  " enclave_u.h"
  "../../libPrt_static.pdb"
  "../../libPrt_static.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Prt_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
