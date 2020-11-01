
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"
// plane
// {
//   <0,1,0,>,2
//   texture {pigment {White}}
// }

light_source {
  <-5,20,50>  
  color White 
}

light_source {
  <-50,50, 50>  
  color Blue 
}

camera {
  location <-2,1,-5>
  look_at <1,1,0>     
}  
plane
{
    -y, 2
    pigment {checker White Tan}
}


sphere { <1,0,1>, 1 texture {T_Stone1} }
sphere { <0,-0.5,0>, 0.5 texture {T_Wood1} }