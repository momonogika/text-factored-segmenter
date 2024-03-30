# TextFactoredSegmenter

TextFactoredSegmenter is a reformulated text tokenizer for machine translation primarily aimed at _factoring shared properties of words_, such as casing or spacing, and serves as the underlying structure of the Microsoft Translator.
This improved tokenizer encodes tokens in the form `WORDPIECE|factor1|factor2|...|factorN`.
This encoding syntax is directly compatible with the [Marian Neural Machine Translation Toolkit](https://github.com/marian-nmt/marian).
To use TextFactoredSegmenter with other toolkits, an implementation of a parser for this format, modification of the embedding lookup and, to use factors on the target side, the beam decoder is required.
The term "TextFactoredSegmenter" applies to both a segmentation library and an encoding of text.

TextFactoredSegmenter not only segments words into subwords, or _word pieces_, using the popular [SentencePiece](https://github.com/google/sentencepiece) library under the hood, but also robustly handles numerals, unknown characters, allows for "phrase fixing", supports continuous scripts and much more.

## Prerequisites

To build TextFactoredSegmenter, you will need to install the following dependencies:

#### Linux
```
sudo apt-get install dotnet-sdk-3.1
sudo apt-get install dotnet-runtime-3.1
```
And SentencePiece. In the Windows version, SentencePiece is invoked via the SentencePiece command-line tools. It has not been tested whether the [vcpkg installation](https://github.com/google/sentencepiece#installation) works.

## Contributing

This project welcomes contributions and suggestions. For details, visit https://cla.opensource.microsoft.com.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.