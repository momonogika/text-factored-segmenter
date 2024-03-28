# TextFactoredSegmenter

TextFactoredSegmenter is a reformulated text tokenizer for machine translation primarily aimed at _factoring shared properties of words_, such as casing or spacing, and serves as the underlying structure of the Microsoft Translator.
This improved tokenizer encodes tokens in the form `WORDPIECE|factor1|factor2|...|factorN`.
This encoding syntax is directly compatible with the [Marian Neural Machine Translation Toolkit](https://github.com/marian-nmt/marian).
To use TextFactoredSegmenter with other toolkits, an implementation of a parser for this format, modification of the embedding lookup and, to use factors on the target side, the beam decoder is required.
The term "TextFactoredSegmenter" applies to both a segmentation library and an encoding of text.

TextFactoredSegmenter not only segments words into subwords, or _word pieces_, using the popular [SentencePiece](https://github.