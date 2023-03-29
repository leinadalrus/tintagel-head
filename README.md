# night-12
###### *Production bolstered by a talented crew of zanies - another commedia dell'arte stock characterizer*

Experimental project in creating a basic UI in Raylib 4.5, 
  so that the there can be a means to programme the Closed-Captioning of a web application using a `.vtt` files.
  
* It also uses a Postgres Database Connector with Rust, but also should have a C99 counterpart which further access Postgres' API on Linux.
* Odin (Odin-lang) is being used as means to do Data-oriented programming with UI components, 
  although this does seem redundant, Odin already offers a nearly first-class support for Raylib as a vendor.
  * Odin also enables us to write code similar in practice if we had Ryan Fleury's DataDesk, alas DataDesk is unavailable anymore to the public.
* Zig (Zig-lang) is like the little brother to Rust. It just helps us write fast-failing functions/features for C interoptability.
  * Zig enables us to interop with C without use of a lot of dependencies like in Rust, 
    and has a really good testing syntax, and try-catch-final syntactic sugar.
    
 And C99 is also employed because I love C, 
  but I tend to shoot myself in the foot with it, which is as to why am experimenting with new and old technologies.
    
Might in turn make this into a 'Type-fighter/ARPG' kinda project to make it a bit more coherent when invisioning the system.
