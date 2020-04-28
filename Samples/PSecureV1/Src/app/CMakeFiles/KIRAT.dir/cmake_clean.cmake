file(REMOVE_RECURSE
  "enclave_u.c"
  " enclave_u.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/KIRAT.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
