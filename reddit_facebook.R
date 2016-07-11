


setwd('~/Downloads')
reddit<-read.csv('reddit.csv')
facebook<-read.csv("pseudo_facebook.tsv",sep='\t')
summary(reddit)
str(reddit)

levels(reddit$age.range)
##install girdExtra package from Tools<-Install Packages<-ggplot2
library(ggplot2)
##install girdExtra package from Tools<-Install Packages<-girdExtra
library(gridExtra)
###Graph 1: Histogram for age and marital status of reddit users####
qplot(data=reddit,x=age.range)
qplot(data=reddit,x=marital.status)
###Graph 2: Histogram (reorganized) for age and marital status of reddit users####
reddit$age.range<-ordered(reddit$age.range,levels<-c('Under 18', '18-24','25-34','45-54','55-64','65 of Above'))
qplot(data=reddit,x=age.range)



names(facebook)
###Graph 3: Histogram and frequency polygon of friend count by gender of Fcebook users####
q1<-qplot(x=friend_count,data=subset(facebook,!is.na(gender)),binwidth=30,xlim=c(0,1000))+facet_wrap(~gender)
q2<-qplot(x=friend_count,data=subset(facebook,!is.na(gender)),binwidth=30,geom='freqpoly',color=gender,xlim=c(0,1000))
grid.arrange(q1,q2,ncol=1)

###Graph 4: Frequency polygons of likes recievied count and mobile likes count##
###by gender of Fcebook users####
q3<-qplot(x=likes_received,data=subset(facebook,!is.na(gender)),geom='freqpoly',color=gender,binwidth=0.1)+scale_x_continuous()+scale_x_log10()
q4<-qplot(x=mobile_likes,data=subset(facebook,!is.na(gender)),geom='freqpoly',color=gender)+scale_x_continuous()+scale_x_log10()
grid.arrange(q3,q4,ncol=1)

by(facebook$friend_count,facebook$gender,summary)
###Graph 5: Histograms of Data transformation friend count##
p1<-qplot(x=friend_count,data=facebook)
p2<-qplot(x=log10(friend_count+1),data=facebook) ##log Transformation of data
p3<-qplot(x=sqrt(friend_count),data=facebook)   
grid.arrange(p1,p2,p3,ncol=1)

