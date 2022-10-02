# How to Contribute

Here is how you can contribute a new problems.

- Pick a problem, and create a folder for it inside `articles\problems\your-folder-name`
    - The folder name should not contain spaces, and delimiter `-` should be used
    - Use lower case alphabets, only use upper case when needed
- Now create a `index.md` file.
    - It should follow this structure.
    - First it should have some metadata

      ```txt
      ---
      title: problem title
      hide:
        - navigation
      tags:
        - tag1
        - tag2
      ---
      ```

    - After that you can begin your problem statement

      ```txt
      ## Problem

      - describe the problem here
      - and more about it
      ```

    - Now give some sample test case and corresponding output
      also describe the input format and output format if necessary.

      ```txt
      ### Input

      - here you will give input and corresponding output
      - you can also include a explanation
      ```

    - Now the section for solutions begin

      ```txt
      ## Solutions
      ```

    - Choose a suitable title for your solution, and comment the file name
      you will use for its code, also no spaces in this name too.

      ```txt
      ### Solution 1

      - here you will explain the algorithm

      `` `cpp
      {{ include_file('solution1.cpp') }}
      `` `
      ```

      Also you should check if your solution produce valid output.

    - In the end there is a section for links to learn more about problem,
      and where can we practice problems.

      ```txt
      ## References ans External Links

      - <https://www.google.com>
      ```

## How to write solutions code

- the code should be formatted
    - for C++ - using the clang formatter
      (config provided in repo base folder [`.clang-format`](.clang-format))

## How to add images

- images go in the `img` folder inside the folder you created.
- also the file name of images should not contain spaces, use `-` as delimiter.
- font used in images should be `Computer Modern`.
- and please remove metadata from the image using `mogrify -strip image-name`
    - this tool is provided by [ImageMagick](https://imagemagick.org/index.php).
