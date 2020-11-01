
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"

light_source {
  <-5,10,-15>  
  color White*2  
}
plane
{
    y, 0
    pigment {checker White Tan}
}


background { color White }

camera {
  // y - wysokość
  //        x,y,z
  location <-10,20,0>
  look_at <0,0,0>     
 
}
// prism { 
//   [właściwości...] H_1, H_2, n, 
//   <Punkt_1>, <Punkt_2>, ... <Punkt_n>  
//   [ open ] [modyfikatory...] }

prism {
    conic_sweep
    0,1,5,
    <3,5>, <-3,5>, <-5,0>, <6,0>,<6,-2>
    // <-1,0>, <0,1>, <0,1>, <1,1>,<1,1>
    pigment { Green }
    rotate <-30, 30, 0> // <x°, y°, z°>
  }


prism {
    linear_spline
    0,1,5,
    <3,5>, <-3,5>, <-5,0>, <6,0>,<6,-2>
    // <-1,0>, <0,1>, <0,1>, <1,1>,<1,1>
    pigment { Red }
    rotate <-90, 0, 0> // <x°, y°, z°>
    scale <0.5, 0.5, 0.5> // <x, y, z>
     translate <0, 0, -1> // <x, y, z>
  }

prism {
    linear_spline
    0,1,5,
    <3,5>, <-3,5>, <-5,0>, <6,0>,<6,-2>
    // <-1,0>, <0,1>, <0,1>, <1,1>,<1,1>
    pigment { Blue }
    rotate <-130, 0, 0> // <x°, y°, z°>
    translate <0, 0, -4> // <x, y, z>
  }

