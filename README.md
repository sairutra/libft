<!-- PROJECT SHIELDS -->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]


<!-- https://stackoverflow.com/questions/30863422/doxygen-how-to-embed-images-on-main-page-for-all-output-formats -->
<!-- https://stackoverflow.com/questions/30863422/doxygen-how-to-embed-images-on-main-page-for-all-output-formats
 -->

<!-- DOXYGEN -->
<span style="display:none">\image html logo.png  \cond </span>
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/sebastianpenning/libft">
    <img src="resources/images/logo.png" alt="Logo" width="225" height="150">
  </a>
  <!-- DOXYGEN -->
  <span style="display:none">\endcond </span>
  <h3 align="center">libft</h3>

  <p align="center">
    libft is a library with functions that are useful for the Codam curriculum
    <br />
    <a href="https://github.com/sebastianpenning/libft"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/sebastianpenning/libft">View Demo</a>
    ·
    <a href="https://github.com/sebastianpenning/libft/issues">Report Bug</a>
    ·
    <a href="https://github.com/sebastianpenning/libft/issues">Request Feature</a>
  </p>
</div>


<!-- TABLE OF CONTENTS -->

<details>
<summary>Table of Contents</summary>
<ol>
<li>
<a  href="#about-the-project">About The Project</a>
<ul>
<li><a  href="#built-with">Built With</a></li>
</ul>
</li>
<li>
<a  href="#getting-started">Getting Started</a>
<ul>
<li><a  href="#installation">Installation</a></li>
</ul>
</li>
<li><a  href="#usage">Usage</a></li>
<li><a  href="#roadmap">Roadmap</a></li>
<li><a  href="#license">License</a></li>
<li><a  href="#acknowledgments">Acknowledgments</a></li>
</ol>
</details>


# About The Project

  
libft is the first project at Codam. Here we created a library that we will use during the rest of our curriculum.  


# Getting Started

This is an example of how you may give instructions on setting up your project locally.

To get a local copy up and running follow these simple example steps.


# Installation
1. Clone the repo, --recursive flag is for submodules, and is necessary.


```sh

git clone https://github.com/sebastianpenning/libft.git --recursive

```
2. cd into directory

```sh

cd libft

```

3. Call the Makefile 

```sh

make

```

4. Copy libft.a and libft.h files over to working directory

```sh

cp {location}/libft.h {working directory}
cp {location}/libft.a {working directory}

```

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/make_libft.png" alt="make_libft" width="1100" height="200">
</a>

# Usage

1. Include libft.h file and libft function in project.

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/include_libft.png" alt="include_libft" width="800" height="175">
</a>


2. Compile with cc

```sh
cc -Wall -Werror -Wextra {project_files.c} libft.a && ./a.out
```

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/compile_libft.png" alt="compile_libft" width="1100" height="125">
</a>



# Tester

The libft tester includes tests for libft, printf, and get_next_line with both unit tests and norminette
tests for all files included. In the future memory tests are planned to be added.

1. cd into libft_tester

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/tester_1.png" alt="include_libft" width="1100" height="120">
</a>

2. Make tests

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/tester_2.png" alt="include_libft" width="1100" height="600">
</a>

# Roadmap

- [ ] ft_strcmpnull (ft_strcmp with ability to compare null strings without segfaulting)
- [ ] memory tests


See the [open issues](https://github.com/sebastianpenning/libft/issues) for a full list of proposed features (and known issues).

# License

Distributed under the MIT License. See `LICENSE.txt` for more information.

 
# Acknowledgments

* [Codam](https://www.codam.nl/about-codam) 
* [Readme Template](https://github.com/othneildrew/Best-README-Template/tree/master)


<!-- MARKDOWN LINKS & resources/IMAGES -->

<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/sebastianpenning/libft.svg?style=for-the-badge

[contributors-url]: https://github.com/sebastianpenning/libft/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/sebastianpenning/libft.svg?style=for-the-badge

[forks-url]: https://github.com/sebastianpenning/libft/network/members

[stars-shield]: https://img.shields.io/github/stars/sebastianpenning/libft.svg?style=for-the-badge

[stars-url]: https://github.com/sebastianpenning/libft/stargazers

[issues-shield]: https://img.shields.io/github/issues/sebastianpenning/libft.svg?style=for-the-badge

[issues-url]: https://github.com/sebastianpenning/libft/issues

[license-shield]: https://img.shields.io/github/license/sebastianpenning/libft.svg?style=for-the-badge

[license-url]: https://github.com/sebastianpenning/libft/blob/main/LICENSE

[C]:https://img.shields.io/badge/-c-black?logo=c&style=social

[C-url]: https://www.learn-c.org/
  

