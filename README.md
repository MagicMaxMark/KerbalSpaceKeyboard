# Kerbal Space Program Keyboard
Arduino code for a Kerbal Space Program Controller
### Pinout

```
             |Y   –––––  A0|
             |X   –––––  A1|
 Joystick    |Bt  ––––-  NC| Arduino
             |VCC ––––-  5v|
             |GND ––––- GND|
             
             |VCC –––––  5v|
 Slider      |GND ––––– GND| Arduino
             |Sig –––––  A2|
          
 Multiplexer |             | Arduino
```

### Controls
- **Right Joystick:** Steering
- **Left Joystick:** RCS
___
- **Top Button of Center Buttons:** Toggle SAS
- **Center Buttons:** SAS Mode
___
- **Numbered Buttons:** Custom Action Groups
___
- **Slider:** Throttle

### Layout
http://ksp-controller-layout.alextheperson.repl.co/
