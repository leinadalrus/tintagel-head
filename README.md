# Tintagel Head

###### _Production bolstered by a talented crew of zanies - another commedia dell'arte stock characterizer_

Experimental project in creating a basic UI in Raylib 4.5 for the sake of Digital Signal Processing and Audio Streaming/Handling.

`.cfg` and-or `.ini` files may also see some application in the future...

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

C++14 is also employed because I love C, alas C++ enables us to use OOP practices better to practice,
but I tend to shoot myself in the foot with it anyways, which is as to why am experimenting with new and old technologies.
