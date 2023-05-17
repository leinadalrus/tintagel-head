# Tintagel Head

###### _Production bolstered by a talented crew of zanies - another commedia dell'arte stock characterizer_

##### The Idea:
Experimental project in creating a basic UI in Raylib 4.5 for the sake of Digital Signal Processing and Audio Streaming/Handling.
_One side of me is like intralogue-ing on the idea I should just use ImGui, but the problem with ImGui is that it doesn't have Emscripten support for web-browser usage._

##### Why not Yew and Tauri?
_Yew and Tauri for Rust would also work really well, but it's the fact in which there's so much magic happening within Yew and Tauri that I won't be able to pull off what I need to do. 
<br>
  Attaching Tauri into a pre-existing project through Cargo with the CLI and as a dependency would be good, but then again, more abstraction.
<br>
  I also chose Leptos because I can isolate a lot of the events occurring in the web-application as components._

As of note: `.cfg` and-or `.ini` files may also see some application in the future...

#### David Tolnay's CXX

David Tolnay's CXX is used for multi-language tiers of the project.

- I have C++14 code in the high-level programming tiers of the project because it's _"safer."_
- It also helps if we in turn have to 'interop' with another user's C++ code, especially with Soloud being unupdated for years.
- 'C99' itself will not allow us to write code in a modern sense with polmorphism/inheritance.
- At some point of the program we'll need to use a Strategy design pattern with a Singleton since we're working with-
  -peripherals after all.

#### `libc`

'libc' enables us to 'interop' with the C code of PortAudio and 'libsndfile' which helps us do some explorative programming.

- We can also test minimally. Testing for trivially but ideal unit tests before doing any form of non-context-free-
  -programming with how software revolves with Singletons combined with Strategy patterns sometimes.

##### The general idea as-of-now...

- Currently using C++14 to create a far-more robust application audio backend.
- Develop a branching Action-Role-Playing Game to reinforce my software engineering fundamentals and learning materials.
- Recreate an old C++14/Rust project in order to further understand FFI-ing and be able to work with multiple technologies without bias(?)

###### Why the use of multiple languages?

C++14 is also employed because I love C, alas C++ enables us to use OOP practices better to practice (preferably Composition over Inheritance),
but I tend to shoot myself in the foot with it anyways, which is as to why am experimenting with new and old technologies.

I will still use C, especially since writing Structures-of-Arrays in C is great, and fun to write pointer-functions for.
