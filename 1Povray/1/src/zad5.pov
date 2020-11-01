
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"

plane
{
    y, 0
    pigment {checker White Tan}
}

light_source {
  <-1,12,-12>  
  color White  
}
 
background { color White }

camera {
  location <0,10,-17>
  look_at <0,4,0>    
}

union{
  prism {
    linear_spline
    0, 8, 3, 
    <0,0>, <1,1>, <0,1>
    rotate <0, 90, -90> 
    translate <0, 1, 1> 
  }
  prism {
    linear_spline
    -1, 8, 3, 
    <0,0>, <1,1>, <0,1>
    rotate <0, 0, 0> 
    translate <0, 1, 0> 
  }
  prism {
    linear_spline
    0, 8, 3, 
    <0,0>, <1,1>, <0,1>
    rotate <180, 90, -90> 
    translate <8, 8, 1> 
  }
  prism {
    linear_spline
    0, 9, 3, // Height 1, Height 2, Number of Points
    <0,0>, <1,1>, <0,1>
    rotate <270, 90, -90> // <x°, y°, z°>
    translate <7, 0, 1> // <x, y, z>
  }
  texture {T_Wood1}
  translate <-9, 0, 0> // <x, y, z>
}


difference {
  box{
    <0,0,0>, <8, 9, 1> // <x, y, z> near lower left corner, <x, y, z> far upper right corner
  }
  union{
    prism {
      0, 8, 3, 
      <0,0>, <1,1>, <0,1>
      rotate <0, 90, -90> 
      translate <0, 1, 1> 
    }
    prism {
      -1, 8, 3, 
      <0,0>, <1,1>, <0,1>
      rotate <0, 0, 0> 
      translate <0, 1, 0> 
    }
    prism {
      0, 8, 3, 
      <0,0>, <1,1>, <0,1>
      rotate <180, 90, -90> 
      translate <8, 8, 1> 
    }
    prism {
      0, 9, 3, // Height 1, Height 2, Number of Points
      <0,0>, <1,1>, <0,1>
      rotate <270, 90, -90> // <x°, y°, z°>
      translate <7, 0, 1> // <x, y, z>
    }
    inverse
  }
  texture {T_Stone1}
}