#HyperQuick algorithm for discrete hypergeometric distribution Aleš Berkopec Faculty of Electrical Engineering, University of Ljubljana, Slovenia Journal of Discrete Algorithms Volume 5 Issue 2, June, 2007 Pages 341-347
#http://dl.acm.org/citation.cfm?id=1240340.1240586
#
#Given N balls, M of which are black and the rest are white, what is the probability that out of n balls selected uniformly at random without replacement, at most x are black
hyperquick <- function(x, n, N, M){
	.C("hyperquick",as.integer(n),as.integer(x),as.integer(N),as.integer(M),as.numeric(0.0))[[5]]
}
qphyper <- function(q, m, n, k, lower.tail = TRUE, log.p = FALSE){
	.C("hyperquick",as.integer(k),as.integer(q),as.integer(m+n),as.integer(m),as.numeric(0.0))[[5]]
}
