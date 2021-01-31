# TermSchem #

This is the TermSchem software development project. 

### Project Description ###

This project is a application that is used to view verilog files in a TUI (Terminal User Interface).

### Software Used ###

* [ncurses](https://en.wikipedia.org/wiki/Ncurses)

### Languages Used ###

* [C](https://devdocs.io/c/)

### Setup Proceedure ###

#### Packages and Modules ####

The following packages should be installed via ``apt`` or ``apt-get``:

```bash
# Linux Packages
sudo apt-get install git
sudo apt-get install make
sudo apt-get install gcc
sudo apt-get install libncurses5-dev libncursesw5-dev
sudo apt-get install graphviz
sudo apt-get install pdflatex
sudo apt-get install texlive
sudo apt-get install texlive-latex-extra
```

Afterwards, run ``make`` to build the executable:

```bash
make
```

#### Configuration ####

No configuration required.

#### Running ####

Launch the executable:

```bash
./bin/termschem
```

### Contacts ###

* [Zachary Hickman](mailto:zh@zacharyhickman.net)
