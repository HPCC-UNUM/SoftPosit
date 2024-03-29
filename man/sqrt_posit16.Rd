% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Rcript.R
\docType{methods}
\name{sqrt_posit16}
\alias{sqrt_posit16}
\title{sqrt}
\usage{
\S4method{sqrt}{posit16}(x)
}
\arguments{
\item{x}{posit16 object.}
}
\value{
A posit16 object.
}
\description{
Returns the square root posit16 object.This is to override the default sqrt function.
}
\examples{
a = new ("posit16" , v = 3L)
b = sqrt(a)
}
