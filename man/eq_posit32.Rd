% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Rcript.R
\docType{methods}
\name{eq_posit32}
\alias{eq_posit32}
\title{==}
\usage{
\S4method{==}{posit32,posit32}(e1, e2)
}
\arguments{
\item{e1}{posit32 object.}

\item{e2}{posit32 object.}
}
\value{
TRUE or FALSE.
}
\description{
Compares two posit32 type objects.This is to override the default == operator.
}
\examples{
a = new ("posit32" , v = 3L)
b = new ("posit32" , v = 4L)
a == b
}
