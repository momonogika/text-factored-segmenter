# TextFactoredSegmenter

TextFactoredSegmenter is a reformulated text tokenizer for machine translation primarily aimed at _factoring shared properties of words_, such as casing or spacing, and serves as the underlying structure of the Microsoft Translator.
This improved tokenizer encodes tokens in the form `WORDPIECE|factor1|factor2|...|factorN`.
This encoding syntax is directly com