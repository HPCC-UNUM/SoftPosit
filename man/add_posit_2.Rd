% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Rcript.R
\docType{methods}
\name{add_posit_2}
\alias{add_posit_2}
\title{+}
\usage{
\S4method{+}{posit_2,posit_2}(e1, e2)
}
\arguments{
\item{e1}{posit_2 object.}

\item{e2}{posit_2 object.}
}
\value{
posit_2 object.
}
\description{
Adds two posit_2 type objects.This is to override the default + operator.
}
\examples{
a = new ("posit_2" , v = 3L , y = 4L )
b = new ("posit_2" , v = 4L , y = 4L )
c = a + b

}
