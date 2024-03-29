% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Rcript.R
\docType{methods}
\name{less_than_posit16}
\alias{less_than_posit16}
\title{<}
\usage{
\S4method{<}{posit16,posit16}(e1, e2)
}
\arguments{
\item{e1}{posit16 object.}

\item{e2}{posit16 object.}
}
\value{
TRUE or FALSE.
}
\description{
Compares two posit16 type objects.This is to override the default < operator.
}
\examples{
a = new ("posit16" , v = 3L)
b = new ("posit16" , v = 4L)
a < b
}
