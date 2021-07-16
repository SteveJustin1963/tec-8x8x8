## tec-8x8x8

there is a special out() op code that allows writing data to both the data and address bus!
so you have 3 registers to make io with in one go.

let use this feature to drive a 8x8x8 cube of leds


use the existing all 2x 8 latch ports from LED's and SPK plus plus add 1 extra 8 port latch 
* or use special OUT commands to put data of 3x bytes on data and address buses, address bus will act as data output
* code in asm and forth 

### cct
https://easyeda.com/editor#id=ed061e9ae9224c60852fb2f375365b3b|acb8d600422a4e25b69171aa71cef963

