# Sampson
Basic 2D/ 3D OpenGL Game Engine

#### *Changes to be done once repo is cloned:*

**General**

- Output Directory -> `$(SolutionDir)bin\$(Configuration)\`
- Intermediate Directory -> `$(SolutionDir)bin\$(Configuration)\Intermediates\`

**VC++ Directories**

- Include Directories -> `$(SolutionDir)Dependencies\GLEW\include;$(SolutionDir)Dependencies\GLFW\include;$(SolutionDir)Dependencies\GLM\include;$(SolutionDir)Dependencies\FreeImage\include;$(SolutionDir)Dependencies\FreeType2;$(IncludePath)`
- Library Directories -> `$(SolutionDir)Dependencies\GLFW\lib-vc2015;$(SolutionDir)Dependencies\GLEW\lib;$(SolutionDir)Dependencies\FreeImage\lib;$(LibraryPath)`

**C/C++ -> Preprocessor**

- Preprocessor Definitions -> `GLEW_STATIC;%(PreprocessorDefinitions)`

**Linker -> Input**

- Additional Dependencies -> `glfw3.lib;glew32s.lib;opengl32.lib;FreeImage.lib;%(AdditionalDependencies)`
