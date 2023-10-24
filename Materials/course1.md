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
##### Multiclass Support Vector Machine (SVM) loss
$L_i=\sum_{j \neq y_i} \max \left(0, s_j-s_{y_i}+\Delta\right)$
( $ReLU$ ??? )

hinge loss: $L_i=\sum_{j \neq y_i} \max \left(0, w_j^T x_i-w_{y_i}^T x_i+\Delta\right)$

Other: squared hinge loss SVM (or L2-SVM)

![margin](https://github.com/Jackcuii/CNN-but-not-CNN/assets/113412207/102cc798-057d-4d4c-955e-3a146f0d445a)

We wish to encode some preference for a certain set of weights W over others to remove this ambiguity.
regularization penalty $R(W)$
$R(W)=\sum_k \sum_l W_{k, l}^2$

Full expression of the loss function:
![图片](https://github.com/Jackcuii/CNN-but-not-CNN/assets/113412207/74b4e3bd-7312-401c-91dc-605d2d1987f0)
Since the L2 penalty prefers smaller and more diffuse weight vectors, the final classifier is encouraged to take into account all input dimensions to small amounts rather than a few input dimensions and very strongly.
##### Softmax Loss
![svmvssoftmax](https://github.com/Jackcuii/CNN-but-not-CNN/assets/113412207/4790eae7-4b63-45a7-8877-242e2f9102b8)
......
Softmax classifier provides “probabilities” for each class. 

We put the word “probabilities” in quotes, however, is that how peaky or diffuse these probabilities are depends directly on the regularization strength λ - which you are in charge of as input to the system. 

the probabilities computed by the Softmax classifier are better thought of as confidences where, similar to the SVM, the ordering of the scores is interpretable, but </font>the absolute numbers (or their differences) technically are not <font color=Red> .

$L_i=-\log \left(\frac{e^{f_{y_i}}}{\sum_j e^{f_j}}\right) \quad$ or equivalently $\quad L_i=-f_{y_i}+\log \sum_j e^{f_j}$

https://deepinout.com/numpy/numpy-questions/32_numpy_cs231n_how_to_calculate_gradient_for_softmax_loss_function.html

![dataflow](https://github.com/Jackcuii/CNN-but-not-CNN/assets/113412207/79e83ea4-a44b-4ac9-9ad5-7efcba664fba)

##### Gradient descent
Nothing much to say.

##### Backward prop
First forward down to calculate the intermediate value.
Then backward to calculate the gradient.
calc it locally not globally!


