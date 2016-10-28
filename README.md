# SNPFinder

## Overview
SNPFinder is a simple alignment-based haplotype variant caller that can be used with metagenomic sequence data. Input to SnipFinder is a [SAM](http://samtools.github.io/hts-specs/SAMv1.pdf) formatted alignment file and a [FASTA](https://en.wikipedia.org/wiki/FASTA_format) formatted reference database. 

## Output
Output is a single [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) formatted text file with three columns: *Gene, Haplotype Pattern, and Occurrence*. The gene corresponds to the reference sequence for which haplotypes were identified within a single or read-pair. The haplotype pattern is the haplotype sequence identified within a single or read-pair. Occurrence is the number of times the current haplotype pattern was identified within a target reference sequence.

## Installation
```bash
$ git clone https://github.com/cdeanj/snpfinder.git
$ cd snpfinder
$ make
$ ./snpfinder
```

## Usage
```bash
$ ./snpfinder [options]
```

## Options

##### `-amr_fp`
Path to fasta formatted resistance database
```bash
$ -amr_fp /path/to/your/resistance_database.fasta
```

##### `-samse`
Path to single-end SAM formatted alignment file
```bash
$ -samse /path/to/your/single_alignment.sam
```

##### `-sampe`
Path to paired-end SAM formatted alignment file
```
$ -sampe /path/to/your/paired_alignment.sam
```

##### `-b`
Boolean flag for filtering on unique alignments
```
$ -b
```

##### `-out_fp`
Output file path
```bash
$ -out_fp /path/to/your/output.txt
```
