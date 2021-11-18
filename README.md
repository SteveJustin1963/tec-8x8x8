## tec-8x8x8

its nice we have the 8x8 addon, and on much the same design we can make a 8x8x8 by adding more latches + 138 chip. 
you can also buy a 8x8x8 kit for under $30 with all the parts, but you cant connect it to the tec-1, or can you? lol

this hack add-on is to use the kit

https://www.banggood.com/Geekcreit-8x8x8-LED-Cube-3D-Light-Square-Blue-LED-Flash-Electronic-DIY-Kit-p-1055438.html

then blast the data to the port using the undocumented out (c) command. but how can it be undocumented when theres a document for this undocumneted opcode?

it goes like this;

```
out (c),a
out (a0-a7 b),a  ; so ‘a’ goes to a0-7 and ‘a’ goes to a8-15

The one we want is

out (c), reg
```

We preload bc, and a then hit out, then it dumps on all three registers at same time; hence

```
ld a,n
out (c),bc [reg pair]
out (a0-7),a  ; a >a0-7 + bc>a0-15 
```

using the out() opcode allows writing to the data and address bus at the same time! we then intersect the data/address lines with the
pcb kit, 

see the circuit of the kit
https://github.com/SteveJustin1963/tec-8x8x8/blob/master/pics/8x8x8-LED-Cube-Image-Circuit-Diagram-Full-Size.png

our cicuit to connect to the kit




 unfinished

 


