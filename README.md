Meta SNP: A simple naive metagenomics variant caller written in C++.

#### Installation
```
git clone https://github.com/cdeanj/meta_snp.git
cd meta_snp
make
./metasnp
```

#### Usage
Usage: ./metasnp [options]

Pipeline Options:

    -amr_fp     STR/FILE        fasta file path	    
    -samse      STR/FILE        single-end sam file path
    -sampe      STR/FILE        paired-end sam file path
    -b          BOOL            filter on unique alignments
    -out_fp     STR/FILE        output file path


#### Output

The output is a tab delimited text file with three columns
```
Gene    Haplotype Pattern   Occurrence
```

* Gene: The gene where haplotypes occurred
* Haplotype Pattern: The haplotype pattern occurring within a gene
* Occurrence: The amount of times a haplotype pattern occurred within a gene

#### Example
Call variants from a paired alignment file
```
./metasnp -amr_fp ref.fa -sampe paired.sam -out_fp result.tabular
```
Call variants from a paired alignment file and filter on unique alignments. To filter, only alignments with a valid XT:A:U tag are considered
```
./metasnp -amr_fp ref.fa -sampe paired.sam -b -out_fp result.tabular
```
