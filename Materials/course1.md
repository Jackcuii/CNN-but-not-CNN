#### NNClassifier
https://cs231n.github.io/classification/
#### Linear Classifier
https://cs231n.github.io/linear-classify/
##### Formalized description
As before, let's assume a training dataset of images $x_i \in R^D$, each associated with a label $y_i$. Here $i=1\ldots N$ and $y_i \in1\ldots K$. That is, we have $\mathbf{N}$ examples (each with a dimensionality $\mathrm{D}$ ) and $\mathbf{K}$ distinct categories. 

We will now define the score function $f: R^D \mapsto R^K$ that maps the raw image pixels to class scores.

$f\left(x_i, W, b\right)=W x_i+b$

![wb](https://github.com/Jackcuii/CNN-but-not-CNN/assets/113412207/e52cb7b5-5be4-407f-b70c-1031a2716497)

Interpretations are in the official note.
(Linear Constraints / Average Templates Matching)
