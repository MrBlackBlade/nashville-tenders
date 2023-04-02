> # ***To-do list***
> 
> - **Add arrays for:**  
>    1. Player objects  
>    2. Player sprites
>    3. Player specific functions *(yes you can array functions wtf)*
>
> - **Add sprites and textures to Player.hpp**  
> - **Move all motion functions into a block that looks like:**  
>   ```cpp
>   // Pressed
>   if (event.type() == Event::KeyPressed)
>   {
>       /* code here */
>   }
>
>   // Released
>   if (event.type() == Event::KeyReleased)
>   {
>       /* code here */
>   }
>   ```
> - **Platform Collision Detection**
> - **Automate the functions for both players using for-loops**
> - **Write jump(), add boolean values to track ability to jump, move, fall, etc.**