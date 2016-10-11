# SnipFinder
SnipFinder is a simple alignment-based haplotype variant caller that can be used with metagenomic sequence data. Input to SnipFinder is an alignment file ([SAM](http://samtools.github.io/hts-specs/SAMv1.pdf)) and a [FASTA](https://en.wikipedia.org/wiki/FASTA_format) formatted reference database. Output is a tab delimited text file with 3 columns: Gene, Haplotype Pattern, and Occurrence. The gene corresponds to the reference sequence for which haplotypes were identified within a single or read-pair. The haplotype pattern is the haplotype sequence identified within a single or read-pair. Occurrence is the number of times the current haplotype pattern was identified within a target reference sequence.

## Installation
```bash
$ git clone https://github.com/cdeanj/snipfinder.git
$ cd snipfinder
$ make
$ ./snipfinder
```

## Usage
```bash
$ ./snipfinder [options]
```

## Options

##### `-amr_fp`
Path to fasta formatted resistance database
```bash
$ -amr_fp /path/to/your/resistance_database.fasta
```

##### `-sam_fp`
Path to SAM formatted alignment file
```bash
$ -sam_fp /path/to/your/alignment.sam
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
