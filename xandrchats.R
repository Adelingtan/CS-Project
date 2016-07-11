##Explanation: Three-sigma limits (3-sigma limits) 
#are used to set the upper and lower control limits 
#in statistical quality control charts. Control charts
#are used to establish limits for a manufacturing or business
#process that is in a state of statistical control. 

##X-bar and R Charts 
##R_i = Xmax − Xmin
##           x-bar chart                                    R Chart ###
##Upper control limit(UCL)= x_bar+A_2*R_bar      UCL=D_4*R_bar      ###
##Center Limit=x_bar                              CL=R_bar          ###
##Lower control limit(LCL)= x_bar-A_2*R_bar      LCL=D_3*R_bar      ###

##Given Data have 80 observations and 20 subgroups, for each subgroup n=4
x<-c(459, 449, 435, 450,
     443,440,442,442,
     457,444,449,444,
     469,463,453,438,
     443,457,445,454,
     444,456,446,457,
     445,449,450,445,
     446,455,449,452,
     444,452,457,440,
     432,463,463,443,
     445,452,453,457,
     456,457,436,457,
     459,445,441,447,
     441,465,438,450,
     460,453,457,438,
     453,444,451,435,
     451,460,450,457,
     422,431,437,429,
     444,431,437,467,
     450,450,454,454)
D = matrix( x, nrow=20, ncol=4,byrow = TRUE) 
D
R<-c()
#R=max(x_i)-min(x_i) 
R<-apply(D, 1,function(x) max(x[x>0])-min(x[x>0]))

x_bar<-mean(x)
#the mean of each observation
x.bar<-apply(D, 1, mean)
r_bar=mean(R)

##n=4  A_2=0.73
xbar_chart_UCL=x_bar+0.73*r_bar
xbar_chart_LCL=x_bar-0.73*r_bar

##n=4  D_4=2.282, D_3=0
R_chart_UCL=r_bar*2.282
R_chart_LCL=r_bar*0
k<-c()
#Determine whether the process is out of control, if any subgroup mean is above or below
##the 3-sigma control limit, then the process is out of control.
ifelse(max(x.bar)<=xbar_chart_UCL&& min(x.bar)>=xbar_chart_LCL,
       paste("According to X-bar Chart, the process is under control"),
       paste("Process is out of control"))


attach(mtcars)
par(mfrow=c(2,1))
##Plot xbar chart, the out of control subgroup maked as red.
plot(1:20,x.bar,type="o",
     col=ifelse((x.bar>xbar_chart_UCL|x.bar<xbar_chart_LCL),"red","blue"),
     lwd = 2, xlab="Subgroups",ylab="Sample Mean",ylim = c(430,465))
title(main='xbar Chart', col.main="red", font.main=4)
abline(a=xbar_chart_UCL, b=0, col = "red") ##UCL Line
abline(a=xbar_chart_LCL, b=0, col = "red") ##LCL Line
abline(a=x_bar, b=0, col = "red")


plot(R,type="o",col="blue",lwd = 2, xlab="Subgroups",ylab="Sample Mean",ylim=c(-1, 46))
title(main='R Chart', col.main="red", font.main=4)
abline(a=R_chart_UCL, b=0, col = "red")  ##UCL Line
abline(a=R_chart_LCL, b=0, col = "red")  ##LCL Line
abline(a=r_bar, b=0, col = "red")
