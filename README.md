![Flag](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Flag_of_the_United_Kingdom_%281-2%29.svg/255px-Flag_of_the_United_Kingdom_%281-2%29.svg.png)

# Class Relationships and Operator Overloading in C++

For the requested assignment, click the link:  
[Assignment](Assignment/)

For the source code, click the link:  
[Code](Code/)

## Overview

This repository contains a C++ program that demonstrates the creation and management of student records with a focus on course registration and grade handling. The project involves two primary classes: `Student` and `Course`. The program illustrates important object-oriented programming (OOP) concepts such as:

- Class relationships (aggregation)
- Operator overloading for handling common operations like comparison and course addition
- Dynamic memory management with exception handling
- Stream manipulation for outputting student data to files

---

## Course Information
- **Course**: [Objected Oriented Programming](https://ice.uniwa.gr/education/undergraduate/courses/object-oriented-programming/)
- **Semester**: 2
- **Program**: [UNIWA](https://www.uniwa.gr/)
- **Department**: [Informatics and Computer Engineering](https://ice.uniwa.gr/)
- **Instructor**: [Georgios Meletiou](https://ice.uniwa.gr/emd_person/17562/)

## Student Information
- **Name**: Athanasiou Vasileios Evangelos
- **Student ID**: ice19390005
- **Status**: Undergraduate

---

## Key Concepts

### 1. **Class Relationships**
#### **Course Class**:
- **Attributes**:
  - `Course Code`: The unique identifier for the course.
  - `Course Name`: The descriptive name of the course.
  - `Course Semester`: The semester in which the course is offered.

#### **Student Class**:
- **Attributes**:
  - **Declared Courses**: The courses a student is currently enrolled in.
  - **Passed Courses**: The courses a student has completed with a grade.
  
### 2. **Operator Overloading**
- **`+=` Operator**: Adds a course to the student's declared courses.
- **Assignment Operator (`=`)**: Copies the attributes of one student into another.
- **Comparison Operators (`==`, `!=`, `<`, `<=`, `>`, `>=`)**: Compares two students based on their current semester.
- **Stream Insertion Operator (`<<`)**: Outputs a student's detailed transcript, including course grades and average GPA, to a stream (console or file).

### 3. **Exception Handling**
- Protects dynamic memory allocation and file operations. If an error occurs (e.g., memory allocation failure or file access issues), the program throws and catches exceptions, providing meaningful error messages.

---

## Functionality

### Key Functions:
- **`+=` Operator**: Adds a course to the student's declared course list.
- **Assignment Operator (`=`)**: Copies a student's attributes to another instance.
- **Comparison Operators**: Compare students based on their academic semester.
- **Stream Insertion Operator (`<<`)**: Outputs detailed transcripts and grades.

---

## Requirements

- **C++ Compiler**: G++ or any standard C++ compiler.
- **Operating System**: Linux/Windows/MacOS.
- **Development Environment**: Command Line or IDE.

---

## Installation and Usage

### 1. Clone the Repository
```bash
git clone https://github.com/Object-Oriented-Programming-aka-Uniwa/Inheritance.git
cd Inheritance
```

### 2. Compile
```bash
g++ -o Inheritance Student.cpp Course.cpp main.cpp
```

### 3. Run
```bash
./Inheritance
```

![Flag](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Flag_of_Greece.svg/255px-Flag_of_Greece.svg.png)

# Σχέσεις Κλάσεων και Υπερφόρτωση Τελεστών σε C++

Για την ζητούμενη εργασία, κάντε κλικ στον σύνδεσμο:  
[Assignment](Assignment/)

Για τον πηγαίο κώδικα, κάντε κλικ στον σύνδεσμο:  
[Code](Code/)

## Επισκόπηση

Αυτό το αποθετήριο περιέχει ένα πρόγραμμα σε C++ που επιδεικνύει τη δημιουργία και τη διαχείριση φοιτητικών εγγραφών με έμφαση στη δήλωση μαθημάτων και τη διαχείριση βαθμολογιών. Το έργο περιλαμβάνει δύο κύριες κλάσεις: `Student` και `Course`. Το πρόγραμμα παρουσιάζει σημαντικές έννοιες αντικειμενοστραφούς προγραμματισμού (OOP) όπως:

- Σχέσεις κλάσεων (aggregation)
- Υπερφόρτωση τελεστών για την επεξεργασία συνήθων λειτουργιών όπως η σύγκριση και η προσθήκη μαθημάτων
- Δυναμική διαχείριση μνήμης με διαχείριση εξαιρέσεων
- Χειρισμός ροών για εξαγωγή δεδομένων φοιτητών σε αρχεία

---

## Πληροφορίες Μαθήματος
- **Μάθημα**: Αντικειμενοστραφής Προγραμματισμός
- **Εξάμηνο**: 2
- **Πρόγραμμα**: [ΠΑΔΑ](https://www.uniwa.gr/)
- **Τμήμα**: [Μηχανικών Πληροφορικής και Υπολογιστών Υπολογιστών](https://ice.uniwa.gr/)
- **Καθηγητής**: [Γεώργιος Μελετίου](https://ice.uniwa.gr/emd_person/17562/)

## Πληροφορίες Φοιτητή
- **Όνομα**: Αθανάσιου Βασίλειος Ευάγγελος
- **Αριθμός Φοιτητή**: ice19390005
- **Κατάσταση**: Προπτυχιακός

---

## Βασικές Έννοιες

### 1. **Σχέσεις Κλάσεων**
#### **Κλάση Course**:
- **Χαρακτηριστικά**:
  - `Κωδικός Μαθήματος`: Ο μοναδικός κωδικός του μαθήματος.
  - `Όνομα Μαθήματος`: Η περιγραφή του μαθήματος.
  - `Εξάμηνο Μαθήματος`: Το εξάμηνο στο οποίο προσφέρεται το μάθημα.

#### **Κλάση Student**:
- **Χαρακτηριστικά**:
  - **Δηλωμένα Μαθήματα**: Τα μαθήματα στα οποία είναι εγγεγραμμένος ο φοιτητής.
  - **Περασμένα Μαθήματα**: Τα μαθήματα που έχει ολοκληρώσει επιτυχώς ο φοιτητής με βαθμό.
  
### 2. **Υπερφόρτωση Τελεστών**
- **Τελεστής `+=`**: Προσθέτει ένα μάθημα στη λίστα των δηλωμένων μαθημάτων του φοιτητή.
- **Τελεστής Αντιστοίχισης (`=`)**: Αντιγράφει τα χαρακτηριστικά ενός φοιτητή σε έναν άλλο.
- **Τελεστές Σύγκρισης (`==`, `!=`, `<`, `<=`, `>`, `>=`)**: Συγκρίνουν δύο φοιτητές βάσει του τρέχοντος εξαμήνου.
- **Τελεστής Εισαγωγής Ροής (`<<`)**: Εξάγει αναλυτικά στοιχεία για τον φοιτητή, συμπεριλαμβανομένων των βαθμών και του μέσου όρου GPA, σε μια ροή (κονσόλα ή αρχείο).

### 3. **Διαχείριση Εξαιρέσεων**
- Προστατεύει την κατανομή δυναμικής μνήμης και τις λειτουργίες αρχείων. Εάν παρουσιαστεί σφάλμα (π.χ. αποτυχία κατανομής μνήμης ή προβλήματα πρόσβασης αρχείου), το πρόγραμμα ρίχνει και διαχειρίζεται εξαιρέσεις, παρέχοντας σχετικές μηνύματα σφαλμάτων.

---

## Λειτουργικότητα

### Κύριες Λειτουργίες:
- **Τελεστής `+=`**: Προσθέτει ένα μάθημα στη λίστα των δηλωμένων μαθημάτων του φοιτητή.
- **Τελεστής Αντιστοίχισης (`=`)**: Αντιγράφει τα χαρακτηριστικά ενός φοιτητή σε έναν άλλο.
- **Τελεστές Σύγκρισης**: Συγκρίνουν φοιτητές βάσει του ακαδημαϊκού τους εξαμήνου.
- **Τελεστής Εισαγωγής Ροής (`<<`)**: Εξάγει αναλυτικές αναφορές με βαθμούς και μέσο όρο GPA.

---

## Απαιτήσεις

- **Μεταγλωττιστής C++**: G++ ή οποιοσδήποτε μεταγλωττιστής C++.
- **Λειτουργικό Σύστημα**: Linux/Windows/MacOS.
- **Περιβάλλον Ανάπτυξης**: Γραμμή Εντολών ή IDE.

---

## Εγκατάσταση και Χρήση

### 1. Κλωνοποίηση του Αποθετηρίου
```bash
git clone https://github.com/Object-Oriented-Programming-aka-Uniwa/Inheritance.git
cd Inheritance
```

### 2. Μεταγλώττιση
```bash
g++ -o Inheritance Student.cpp Course.cpp main.cpp
```

### 3. Εκτέλεση
```bash
./Inheritance
```