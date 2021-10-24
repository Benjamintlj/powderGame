Notes on the program

--- If you get an Compile error ---

This is a list of potental issue you
may face during compilation.

Ignore if it works!!!



This may be because include <SDL.2/SDL.h>
does not exist on your computer,
"<SDL2/SDL.h>" is for MacOS not all
Windows machines.
Therefore if you can run this on MacOS
where it was tested.
Or
"SDL2.framework" was not included in
your frameworks and libraries, to fix
include it, during testing this was
embeded.

One other problem you might have is,
file.txt does not have the correct permissions,
if on MacOS,
finder > find "file.txt" > get info > permissions
> tic all the boxes

Final issue while compiling is that
your directory maybe incorrect,
to fix change your compilers dir to
"powderGame".

