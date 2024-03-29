% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Rcript.R
\docType{methods}
\name{abs_posit16}
\alias{abs_posit16}
\title{abs}
\usage{
\S4method{abs}{posit16}(x)
}
\arguments{
\item{x}{posit16 object.}
}
\value{
A posit16 object.
}
\description{
Returns the absolute value of posit16 object.This is to override the default abs function.
}
\examples{
a = new ("posit16" , v = -3L)
b = abs(a)
}
