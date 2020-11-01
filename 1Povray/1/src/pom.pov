
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"

light_source {
  <0,100,0>  
  color White  
}
 
plane
{
    y, 0
    pigment {checker White Tan}
}


background { color White }

camera {
  location <-10,10,-10>
  look_at <0,0,0>     
}

sphere { <0,0,0>, 0.5 pigment {color rgb <255, 255, 255, 150>} }     

  
// text {
//     ttf "timrom.ttf" "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy" 1, 0
//     pigment { Red }
//     rotate <0, 0, 90> 
// }  
text {
    ttf "timrom.ttf" "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" 1, 0
    pigment { Green }
    rotate <90, 0, 0> 
}
text {
     ttf "timrom.ttf" "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" 1, 0
     pigment { Blue }
    rotate <90, -90, 0> 
 }