
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
  location <20,30,-10>
  look_at <12,0,0>     
 
}
// prism { 
//   [właściwości...] H_1, H_2, n, 
//   <Punkt_1>, <Punkt_2>, ... <Punkt_n>  
//   [ open ] [modyfikatory...] }
#declare Count=0; 

#while (Count < 10)
    prism {
        linear_spline
        0,1,5,
        <3,5>, <-3,5>, <-4,0>, <4,0>,<6,3>
        pigment { Green }
        rotate <-90, 90, 0> // <x°, y°, z°>
        translate <Count*4 - 10, Count, 0> // <x, y, z>

    }
#declare Count=Count+1; 
#end