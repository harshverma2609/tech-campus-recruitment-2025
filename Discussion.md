# Discussion

## Solutions Under Consideration

Upon setting up the problem on efficiently fetching a log from the file, potential solutions under consideration include:

1. Load The Entire File
One such idea was to simply load the log file entirely in the memory so that all filtering on the line would be on dates.
Advantages: Implemented quite easily so once loaded would result in really fast access for log fetch.
- Cons: Since the log file is 1 TB in size, it would consume a huge amount of memory, making it impractical and likely to crash the system.

2. Reading Line by Line:
- The other method was to read the file line by line. It checks each line if the line starts with the given date and appends the matching lines to a new output file.
- Advantages: This method has minimal memory usage because we are only storing one line in memory at a time. It's scalable even for very large files.
- Disadvantages: It is a bit slower than loading the entire file into memory because we have to process each line individually.

3. Using Indexing:
- Another more complicated approach might be to create an index of the logs in advance, say by storing the line numbers or offsets of entries by date, so that queries can be answered very quickly.
Pros: Query time could be extremely fast after the initial index is built.
- Cons: The construction and maintenance of such an index would require enormous storage and pre-processing, which makes this impractical for this particular problem, as the problem asks for an efficient and straightforward solution.

## Final Solution Summary:

The selected solution was reading the log file line by line, checking whether the line starts with the desired date, and writing matching lines to a new output file. This is selected because:

- It avoids the memory issues associated with loading the entire file into memory, which would be quite impossible given its size of 1 TB.
- It allows the program to process files of enormous size without running out of memory or crashing.
- It is simple, straightforward, and does not require complex indexing or preprocessing.
- The time complexity of reading this file line-by-line is O(n), if n is the number of lines in the given file. There is a time complexity of O(m) from the space since m is number of log entries matching the chosen date, hence manageable.

There is a sweet spot for solution simplicity, speed, and low memory usage for this problem solution.

## Steps to Run the C++ solution in VS Code:

1. Set Up the Project Directory
Create the following folder structure for your project:
- farmart
  - output/         (this folder will contain the generated output files that is executable solution.exe file and the output txt file)
  - logs_2024.log   (the log file you will be processing)
  - solution.cpp    (the C++ source code)
where
  logs_2024.log: Place your log file here. This is the file that the program will read from.
  solution.cpp: This is the C++ source code containing the logic to extract logs.
  output: This folder will contain the output files that the program generates.

2. Open the folder in VS Code and create the necessary C++ source code.
3. Configure tasks.json for building the project with g++. (assuming it is already done to compile solution.cpp into an executable solution.exe in the output/ folder.)
4. Configure launch.json for running the program with the Run button (F5).
5. Press F6 to build, then Press F5 to run the program.
6. Enter a date when prompted, and the output txt file will be generated in the output/ folder.
