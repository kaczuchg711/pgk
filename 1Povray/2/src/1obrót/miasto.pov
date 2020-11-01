
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
    pigment {color rgb<0, 0.380, 0.054>}
}

background { color White }

camera {
  location <-10,20,10>
  look_at <10,0,10>
  translate <-10, 0, -10> // <x, y, z>
  rotate <0,(270 / final_clock) * clock,0>
  translate <10, 0, 10> // <x, y, z>
}


// text {
//     ttf "timrom.ttf" "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" 1, 0
//     pigment { Green }
//     rotate <90, 0, 0> 
//     translate <0, 0, -0.5> // <x, y, z>
// }
// text {
//     ttf "timrom.ttf" "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" 1, 0
//     pigment { Blue }
//     rotate <90, -90, 0> 
//  }
 
 
prism {
  // plansza
    0,0.01,4,
    <0,0>, <0,20>, <20,20>, <20,0>
    pigment { Gray }
  } 
box {
  // ulica od x
  <9, 0.1, 0>, 
  <11, 0.1, 20>
}

box {
  // ulica od z
  <0, 0.1, 9>, 
  <20, 0.1, 11>
}

box {
  <12, 0, 12>, 
  <14, 3, 14>
  pigment { Green }
}

box {
  // lewiatan
  <12, 0, 9>, 
  <16, 1, 5>
  pigment { Yellow }
}

box {
  // bloki prawa
  <17, 0, 9>, 
  <18, 2, 5>
  pigment { color rgb <0.411, 0.411, 0.411> }
}

box {
  // bloki prawa
  <19, 0, 9>, 
  <20, 2, 5>
  pigment { color rgb <0.411, 0.411, 0.411> }
}





cylinder {
  <4.5, 0, 16.5>, <4.5, 2, 16.5>, 1 // center of one end, center of other end, radius
 
  texture {T_Stone1}
}

sphere {
  <4.5, 5, 16.5>, 3 // <x, y, z>, radius
  texture {T_Wood3}
  
}



box{
  <15, 0, 12>, 
  <16, 1, 13>
  pigment { Red }
}

box{
  <15, 0, 12>, 
  <16, 1, 13>
  pigment { Red }
  translate <1.5, 0, 0> // <x, y, z>
}

box{
  <15, 0, 12>, 
  <16, 1, 13>
  pigment { Red }
    translate <1.5, 0, 1.5> // <x, y, z>
}

box{
  <15, 0, 12>, 
  <16, 1, 13>
  pigment { Red }
    translate <0, 0, 1.5> // <x, y, z>
}

box {
  <2, 0, 12>, 
  <8, 1, 13>
  pigment { Blue }
}

box {
  <2, 0, 1>, 
  <8, 2, 7>
  pigment { Orange }
}

cylinder {
  <12, 0, 1>, <12, 1, 1>, 0.1 // center of one end, center of other end, radius
  pigment {color rgb <0.521, 0.243, 0>}
}



sphere {
  // drzewo
 <12, 1, 1>, 0.5 // <x, y, z>, radius
  pigment {color rgb <0, 1, 0>}
}
