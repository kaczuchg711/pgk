
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"

global_settings
{
  max_trace_level 100
}

light_source {
  <0,10,-15>  
  color<1, 0.988, 0.780>
}
 
plane {
    y, 0
    pigment {checker White Tan}
}


background { color White }

camera {
  location <8,10,-15>
  look_at <8,5,0>     
}

// intersection
box { 
    <-1.5, -1, -1>, <0.5, 1, 1>  
    translate<0,4,0>
    pigment{Blue}
}
cylinder {
    <0.5, 0, -1>, <0.5, 0, 1>, 1
    translate<0,7,0> 
    pigment{Red}
}

intersection {
    box { <-1.5, -1, -1>, <0.5, 1, 1> }
    cylinder { <0.5, 0, -1>, <0.5, 0, 1>, 1 }
    translate <0, 1, 0> // <x, y, z>
    pigment{Green}
}

text {
    ttf "timrom.ttf" "  intersection" 1, 0
    rotate <90, 0, 0> 
    translate <-3, 0, -2> // <x, y, z>
}

// difference
box {
     <-1.5, -1, -1>, <0.5, 1, 1>
    translate <6, 6, 0> 
    pigment{Red}
}

cylinder {
    <-0.5, 0, -1>, <-0.5, 0, 1>, 0.5
    open
    translate <6, 3.5, 0> // <x, y, z>
    pigment{Blue}
}

difference {
    box { <-1.5, -1, -1>, <0.5, 1, 1> }
    cylinder { <-0.5, 0, -1>, <-0.5, 0, 1>, 0.5 open}
    translate <6, 1, 0> // <x, y, z>
    pigment{Green}
}

text {
    ttf "timrom.ttf" "  difference" 1, 0
    rotate <90, 0, 0> 
    translate <3, 0, -2> // <x, y, z>
}



// union
box {
    <-1.5, -1, -1>, <0.5, 1, 1> 
    translate <11, 4.5, 0> // <x, y, z>
    pigment{color<0,0,1,0.9>}
}

cylinder {
    <0.5, 0, -1>, <0.5, 0, 1>, 1
    open
    translate <11, 7, 0> // <x, y, z>
    pigment{color<1,0,0,0.9>}
}
    
union {
    box { <-1.5, -1, -1>, <0.5, 1, 1> pigment{color<0,0,1,0.9>}}
    cylinder { <0.5, 0, -1>, <0.5, 0, 1>, 1 open pigment{color<1,0,0,0.9> }}
    translate <11, 1, 0> // <x, y, z>
    
}

// merge

text {
    ttf "timrom.ttf" "  union" 1, 0
    rotate <90, 0, 0> 
    translate <9.5, 0, -2> // <x, y, z>
}

cylinder {
    <0.5, 0, -1>, <0.5, 0, 1>, 1
    open
    translate <15, 7, 0> // <x, y, z>
    pigment{color<1,0,0,0.5>}
    
}


box {
    <-1.5, -1, -1>, <0.5, 1, 1> 
    translate <15, 4.5, 0> // <x, y, z>
    pigment{color<0,0,1,0.9>}
}


merge {
    box { <-1.5, -1, -1>, <0.5, 1, 1> pigment{color<0,0,1,0.9>}}
    cylinder { <0.5, 0, -1>, <0.5, 0, 1>, 1 open pigment{color<1,0,0,0.9>} }
    translate <15, 1, 0> // <x, y, z>
}

text {
    ttf "timrom.ttf" "  merge" 1, 0
    rotate <90, 0, 0> 
    translate <14, 0, -2> // <x, y, z>
}