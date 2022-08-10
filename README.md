# FdF 🗻

![FdF 42](https://user-images.githubusercontent.com/108487635/183720333-4ceb4dbd-21a3-4a13-bf71-5e61c3731bc8.png)

<h2>This project is about creating a simple wireframe model of a 3D landscape in isometric projection.</h2>

<h3>The coordinates of the landscape are stored in a .fdf file passed as a parameter to
your program.</h3>

<h3>Each number represents a point in space:</h3>

  • The horizontal position corresponds to its axis.
  
  • The vertical position corresponds to its ordinate.
  
  • The value corresponds to its altitude.
  
![Map Example](https://user-images.githubusercontent.com/108487635/183723748-99754a13-46e4-4883-953e-6def4088ddf9.png) ![fdf Cut](https://user-images.githubusercontent.com/108487635/183851826-5d5f59bd-ef01-4706-aca7-b7f9e4df6edd.png)


<h3>Bonus list:</h3>

  • Include one extra projection (such as parallel or conic)!
  
  • Zoom in and out.
  
  • Translate your model.
  
  • Rotate your model.
  
  • Add one more bonus of your choice.
  
<h3>How to use: </h3>

    Change projection:
      • isometric (default) use I
      • parallel use P
    
    Rotate:
      • Mouse
      • Keys from 1 to 6

    Move
      • Arrow Keys

    Zoom:
      • Mouse Scroll
      • - or + keys
      
    Change distance:
      • < and > keys
    
    Exit
      • Escape
  
<h2>Build: </h2>
    
    make && ./fdf <path_to_.fdf_file>

![ClearlyDefined Score](https://img.shields.io/badge/success-125%2F100-brightgreen)
