
struct Cbox {
	float x;
	float y;
	float z;
	float sx;
	float sy;
	float sz;
};

Cbox newCBox(float x, float y, float z, float sx, float sy, float sz);
void initCBoxes();
void actionCBoxes();

#define maxCBoxes 1000
Cbox Cboxes[maxCBoxes];
int CboxAmount;

#define playerSize 0.5f
#define playerHeight 1.0f

Cbox newCBox(float x, float y, float z, float sx, float sy, float sz) {
	CboxAmount++;
	Cbox theBox;
	theBox.x = x;
	theBox.y = y;
	theBox.z = z;
	theBox.sx = sx;
	theBox.sy = sy;
	theBox.sz = sz;
	return theBox;
}

void initCBoxes() {

	CboxAmount = 0;

	/*
	// Quiz 4 map
	Cboxes[CboxAmount - 1] = newCBox(0.0, -10.0, 0.0, 200.0, 20.0, 200.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, 0.0, 11.0, 60.0, 40.0, 2.0);
	*/






	// LV -1 intro Map
	if (currentLevel == -1) {

		Cboxes[CboxAmount - 1] = newCBox(-89.314995, -40.0, -24.910002, 218.39, 80.0, 80.0);
		Cboxes[CboxAmount - 1] = newCBox(-11.355, -1.0, 21.585, 26.39, 2.0, 16.210001);
		Cboxes[CboxAmount - 1] = newCBox(5.64, -1.0, 18.555, 9.179999, 2.0, 12.110001);
		Cboxes[CboxAmount - 1] = newCBox(10.98, -1.0, 13.215, 9.18, 2.0, 12.110001);
		Cboxes[CboxAmount - 1] = newCBox(24.505001, -1.0, -10.94, 13.83, 2.0, 23.28);
		Cboxes[CboxAmount - 1] = newCBox(21.475, -1.0, 2.25, 9.389999, 2.0, 11.36);
		Cboxes[CboxAmount - 1] = newCBox(30.86, -1.0, -7.87, 5.659998, 2.0, 11.360001);
		Cboxes[CboxAmount - 1] = newCBox(30.855, -1.0, -2.57, 3.290001, 2.0, 4.56);
		Cboxes[CboxAmount - 1] = newCBox(33.52, -1.0, -5.875, 3.2800007, 2.0, 4.5499997);
		Cboxes[CboxAmount - 1] = newCBox(27.57, -1.0, 1.745, 3.2799988, 2.0, 4.55);
		Cboxes[CboxAmount - 1] = newCBox(26.295, -1.0, 3.665, 3.290001, 2.0, 4.55);
		Cboxes[CboxAmount - 1] = newCBox(28.575, -1.0, 0.21500003, 3.289999, 2.0, 4.55);
		Cboxes[CboxAmount - 1] = newCBox(21.435001, -1.0, 10.16, 3.289999, 2.0, 4.5599995);
		Cboxes[CboxAmount - 1] = newCBox(23.225, -1.0, 8.12, 3.290001, 2.0, 4.5599995);
		Cboxes[CboxAmount - 1] = newCBox(22.345001, -1.0, 9.05, 3.289999, 2.0, 4.56);
		Cboxes[CboxAmount - 1] = newCBox(19.925, -1.0, 11.885, 3.289999, 2.0, 4.55);
		Cboxes[CboxAmount - 1] = newCBox(16.765, -1.0, 15.125, 3.29, 2.0, 4.549999);
		Cboxes[CboxAmount - 1] = newCBox(15.405, -1.0, 16.375, 3.289999, 2.0, 4.549999);
		Cboxes[CboxAmount - 1] = newCBox(11.725, -1.0, 19.654999, 3.29, 2.0, 4.550001);
		Cboxes[CboxAmount - 1] = newCBox(10.27, -1.0, 20.935, 3.2799997, 2.0, 4.549999);
		Cboxes[CboxAmount - 1] = newCBox(3.475, -1.0, 25.849998, 4.17, 2.0, 4.5599995);
		Cboxes[CboxAmount - 1] = newCBox(-7.975, -1.0, 28.79, 12.53, 2.0, 4.5599995);
		Cboxes[CboxAmount - 1] = newCBox(5.78, -1.0, 24.77, 4.4800005, 2.0, 3.4799995);
		Cboxes[CboxAmount - 1] = newCBox(7.9849997, -1.0, 24.595001, 2.35, 2.0, 2.3900013);
		Cboxes[CboxAmount - 1] = newCBox(5.385, -1.0, 26.535, 2.35, 2.0, 2.3899994);
		Cboxes[CboxAmount - 1] = newCBox(2.47, -1.0, 28.15, 2.3600001, 2.0, 2.380001);
		Cboxes[CboxAmount - 1] = newCBox(0.06999999, -1.0, 29.355, 3.56, 2.0, 2.3899994);
		Cboxes[CboxAmount - 1] = newCBox(-14.535, -1.0, 29.36, 3.5499992, 2.0, 2.3799992);
		Cboxes[CboxAmount - 1] = newCBox(-17.880001, -1.0, 28.935, 3.5599995, 2.0, 2.3899994);
		Cboxes[CboxAmount - 1] = newCBox(9.57, -1.0, 22.880001, 3.5600004, 2.0, 2.3799992);
		Cboxes[CboxAmount - 1] = newCBox(12.735001, -1.0, 19.805, 3.5500002, 2.0, 2.3899994);
		Cboxes[CboxAmount - 1] = newCBox(14.02, -1.0, 18.835, 3.5600004, 2.0, 2.3900013);
		Cboxes[CboxAmount - 1] = newCBox(17.51, -1.0, 15.42, 3.5600014, 2.0, 2.380001);
		Cboxes[CboxAmount - 1] = newCBox(18.805, -1.0, 14.29, 3.5499992, 2.0, 2.3799992);
		Cboxes[CboxAmount - 1] = newCBox(20.725, -1.0, 12.325001, 3.5499992, 2.0, 2.3900003);
		Cboxes[CboxAmount - 1] = newCBox(25.205, -1.0, 8.415, 2.1500015, 2.0, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(26.224998, -1.0, 6.565, 2.1499996, 2.0, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(27.97, -1.0, 4.425, 2.1599998, 2.0, 1.8300002);
		Cboxes[CboxAmount - 1] = newCBox(29.295, -1.0, 2.6, 2.1500015, 2.0, 1.84);
		Cboxes[CboxAmount - 1] = newCBox(30.265, -1.0, 0.765, 2.1499996, 2.0, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(32.370003, -1.0, -1.9950001, 2.1599998, 2.0, 1.83);
		Cboxes[CboxAmount - 1] = newCBox(33.645, -1.0, -3.6100001, 2.1500015, 2.0, 1.8400002);
		Cboxes[CboxAmount - 1] = newCBox(11.835, -1.0, 21.904999, 2.1499996, 2.0, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(8.875, -1.0, 24.294998, 2.1499996, 2.0, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(6.26, -1.0, 26.35, 2.1600003, 2.0, 1.8400002);
		Cboxes[CboxAmount - 1] = newCBox(3.7200003, -1.0, 27.93, 2.16, 2.0, 1.8400002);
		Cboxes[CboxAmount - 1] = newCBox(1.685, -1.0, 28.99, 2.15, 2.0, 1.8400002);
		Cboxes[CboxAmount - 1] = newCBox(5.83, 3.63, 24.675, 2.1599998, 9.34, 1.8299999);
		Cboxes[CboxAmount - 1] = newCBox(8.65, 3.63, 22.310001, 2.4800005, 9.34, 2.460001);
		Cboxes[CboxAmount - 1] = newCBox(0.0, 3.96, 18.255001, 3.62, 8.6, 3.6299992);
		Cboxes[CboxAmount - 1] = newCBox(-16.630001, 3.96, 16.85, 3.6200008, 8.6, 3.62);
		Cboxes[CboxAmount - 1] = newCBox(-21.86, 3.96, 15.405, 3.6200008, 8.6, 6.51);
		Cboxes[CboxAmount - 1] = newCBox(-27.105, 3.96, 10.795, 9.629999, 8.6, 6.51);
		Cboxes[CboxAmount - 1] = newCBox(-30.85, 3.96, 9.44, 5.920002, 8.6, 6.52);
		Cboxes[CboxAmount - 1] = newCBox(-31.68, 3.96, 1.675, 5.92, 8.6, 3.65);
		Cboxes[CboxAmount - 1] = newCBox(-34.8, 3.96, 4.9750004, 5.919998, 8.6, 3.65);
		Cboxes[CboxAmount - 1] = newCBox(-35.84, 3.96, -0.58500004, 5.919998, 8.6, 3.65);
		Cboxes[CboxAmount - 1] = newCBox(-38.78, 3.96, -3.895, 5.920002, 8.6, 3.6499999);
		Cboxes[CboxAmount - 1] = newCBox(-44.03, 3.96, -4.785, 5.920002, 8.6, 3.65);
		Cboxes[CboxAmount - 1] = newCBox(-48.6, 3.96, -7.985, 5.920002, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-57.465, 3.96, -9.085, 13.93, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-66.275, 3.96, -11.715, 13.25, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-70.979996, 3.96, -14.85, 3.840004, 8.6, 3.6400003);
		Cboxes[CboxAmount - 1] = newCBox(-79.240005, 3.96, -10.525, 13.879997, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-89.244995, 3.96, -12.184999, 6.1500015, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-97.805, 3.96, -10.645, 11.089996, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-108.88, 3.96, -11.815001, 11.080002, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-116.215, 3.96, -12.934999, 9.049995, 8.6, 3.6500006);
		Cboxes[CboxAmount - 1] = newCBox(-129.525, 3.96, -12.09, 17.87001, 8.6, 3.6399994);
		Cboxes[CboxAmount - 1] = newCBox(-142.76001, 3.96, -11.665, 9.039993, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-132.435, 3.96, -14.575, 2.6100006, 8.6, 1.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-149.12, 3.96, -10.745, 3.6600037, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-152.88501, 3.96, -7.4350004, 3.9900055, 8.6, 3.65);
		Cboxes[CboxAmount - 1] = newCBox(-159.815, 3.96, -6.375, 9.949997, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-169.625, 3.96, -7.495, 9.950012, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-177.70999, 3.96, -8.245, 9.939987, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-182.315, 3.96, -9.29, 9.949997, 8.6, 3.6399999);
		Cboxes[CboxAmount - 1] = newCBox(-185.735, 3.96, -11.405, 9.950012, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-183.22, 3.96, -28.619999, 14.980011, 8.6, 3.6400013);
		Cboxes[CboxAmount - 1] = newCBox(-188.965, -0.45, -20.42, 9.949997, 1.1, 14.44);
		Cboxes[CboxAmount - 1] = newCBox(-189.465, -0.35, -20.42, 9.949997, 1.1, 14.44);
		Cboxes[CboxAmount - 1] = newCBox(-189.965, -0.25, -20.42, 9.949997, 1.1, 14.44);
		Cboxes[CboxAmount - 1] = newCBox(-190.465, -0.14999999, -20.42, 9.949997, 1.1, 14.44);
		Cboxes[CboxAmount - 1] = newCBox(-190.965, -0.050000012, -20.42, 9.949997, 1.1, 14.44);
		Cboxes[CboxAmount - 1] = newCBox(-190.045, 3.96, -18.404999, 1.0899963, 8.6, 1.0100002);
		Cboxes[CboxAmount - 1] = newCBox(-190.045, 3.96, -21.6, 1.0899963, 8.6, 1.0200005);
		Cboxes[CboxAmount - 1] = newCBox(-191.495, 3.96, -16.075, 3.0299988, 8.6, 5.8500004);
		Cboxes[CboxAmount - 1] = newCBox(-191.495, 3.96, -23.915, 3.0299988, 8.6, 5.8500004);
		Cboxes[CboxAmount - 1] = newCBox(-193.895, 1.72, -19.985, 1.9100037, 4.12, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-173.81, 3.96, -32.195, 6.5400085, 8.6, 3.6499996);
		Cboxes[CboxAmount - 1] = newCBox(-170.185, 3.96, -34.195, 6.529999, 8.6, 3.6500015);
		Cboxes[CboxAmount - 1] = newCBox(-164.26999, 3.96, -35.745, 6.5399933, 8.6, 3.6500015);
		Cboxes[CboxAmount - 1] = newCBox(-159.035, 3.96, -35.395, 4.3899994, 8.6, 3.6500015);
		Cboxes[CboxAmount - 1] = newCBox(-154.775, 3.96, -36.905, 4.3899994, 8.6, 3.6499977);
		Cboxes[CboxAmount - 1] = newCBox(-151.17499, 3.96, -36.245, 2.949997, 8.6, 3.6500015);
		Cboxes[CboxAmount - 1] = newCBox(-148.35999, 3.96, -38.325, 4.3600006, 8.6, 3.6500015);
		Cboxes[CboxAmount - 1] = newCBox(-141.76999, 3.96, -39.39, 9.319992, 8.6, 3.6399994);
		Cboxes[CboxAmount - 1] = newCBox(-129.92, 3.96, -35.565, 15.119995, 8.6, 4.290001);
		Cboxes[CboxAmount - 1] = newCBox(-116.92, 3.96, -38.945, 11.339996, 8.6, 4.290001);
		Cboxes[CboxAmount - 1] = newCBox(-114.89, 3.96, -36.68, 4.800003, 8.6, 4.279999);
		Cboxes[CboxAmount - 1] = newCBox(-108.91, 3.96, -42.485, 4.7999954, 8.6, 4.290001);
		Cboxes[CboxAmount - 1] = newCBox(-104.21, 3.96, -41.445, 4.800003, 8.6, 4.290001);
		Cboxes[CboxAmount - 1] = newCBox(-99.96, 3.96, -40.864998, 4.800003, 8.6, 4.289997);
		Cboxes[CboxAmount - 1] = newCBox(-104.9, 3.96, -35.96, 3.2799988, 8.6, 3.0);
		Cboxes[CboxAmount - 1] = newCBox(-96.585, 3.96, -37.129997, 4.550003, 8.6, 4.380001);
		Cboxes[CboxAmount - 1] = newCBox(-86.905, 3.96, -36.535, 6.3099976, 8.6, 5.1100006);
		Cboxes[CboxAmount - 1] = newCBox(-91.3, 3.96, -35.66, 6.2999954, 8.6, 5.0999985);
		Cboxes[CboxAmount - 1] = newCBox(-80.315, 3.96, -39.505, 8.049995, 8.6, 5.1100006);
		Cboxes[CboxAmount - 1] = newCBox(-77.54, 3.96, -36.125, 2.5, 8.6, 3.0899963);
		Cboxes[CboxAmount - 1] = newCBox(-72.6, 3.96, -40.165, 7.5, 8.6, 3.0900002);
		Cboxes[CboxAmount - 1] = newCBox(-67.990005, 3.96, -37.144997, 4.9800034, 8.6, 4.09);
		Cboxes[CboxAmount - 1] = newCBox(-63.54, 3.96, -35.775, 4.080002, 8.6, 4.09);
		Cboxes[CboxAmount - 1] = newCBox(-59.105003, 3.96, -37.445, 4.91, 8.6, 5.9300003);
		Cboxes[CboxAmount - 1] = newCBox(-51.824997, 3.96, -41.405, 14.369999, 8.6, 2.5699997);
		Cboxes[CboxAmount - 1] = newCBox(-39.4, 3.96, -39.49, 11.439999, 8.6, 3.6800003);
		Cboxes[CboxAmount - 1] = newCBox(-30.3, 3.96, -37.43, 6.8199997, 8.6, 3.6800003);
		Cboxes[CboxAmount - 1] = newCBox(-21.564999, 3.96, -34.95, 13.49, 8.6, 3.6800003);
		Cboxes[CboxAmount - 1] = newCBox(-11.425, 3.96, -32.445, 9.07, 8.6, 3.6699982);
		Cboxes[CboxAmount - 1] = newCBox(-1.7099999, 3.96, -35.14, 10.78, 8.6, 3.6800003);
		Cboxes[CboxAmount - 1] = newCBox(10.33, 3.96, -31.220001, 13.920001, 8.6, 12.460001);
		Cboxes[CboxAmount - 1] = newCBox(14.59, 3.96, -22.25, 6.9399996, 8.6, 5.700001);
		Cboxes[CboxAmount - 1] = newCBox(9.955, 3.96, -19.565, 3.4300003, 8.6, 3.4500008);
		Cboxes[CboxAmount - 1] = newCBox(17.59, 3.96, -18.27, 4.220001, 8.6, 2.5599995);
		Cboxes[CboxAmount - 1] = newCBox(18.455, 3.96, -15.195, 3.709999, 8.6, 3.670001);
		Cboxes[CboxAmount - 1] = newCBox(26.119999, 3.96, -15.950001, 11.699999, 8.6, 3.6800013);
		Cboxes[CboxAmount - 1] = newCBox(29.805, 3.96, -12.299999, 5.8500004, 8.6, 3.8000002);
		Cboxes[CboxAmount - 1] = newCBox(32.195, 3.96, -9.345, 3.4700012, 8.6, 2.8500004);
		Cboxes[CboxAmount - 1] = newCBox(26.154999, 3.96, -10.16, 2.33, 8.6, 2.5599995);
		Cboxes[CboxAmount - 1] = newCBox(34.510002, 3.96, -5.995, 4.119999, 8.6, 3.9499998);
		Cboxes[CboxAmount - 1] = newCBox(22.065, 3.96, 1.285, 2.7299995, 8.6, 2.59);
		Cboxes[CboxAmount - 1] = newCBox(24.075, 3.96, 6.035, 4.1900005, 8.6, 4.17);
		Cboxes[CboxAmount - 1] = newCBox(-8.605, 3.96, 16.095, 3.0299997, 8.6, 3.249999);
		Cboxes[CboxAmount - 1] = newCBox(-10.83, 3.96, 14.645, 1.8400002, 8.6, 1.71);
		Cboxes[CboxAmount - 1] = newCBox(-6.25, 3.96, 27.86, 2.1999998, 8.6, 2.3199997);
		Cboxes[CboxAmount - 1] = newCBox(-8.15, 3.96, 26.01, 2.1999998, 8.6, 2.3199997);
		Cboxes[CboxAmount - 1] = newCBox(-12.07, 3.96, 27.35, 5.96, 8.6, 7.040001);
		Cboxes[CboxAmount - 1] = newCBox(-25.215, 3.96, 22.380001, 5.49, 8.6, 9.08);
		Cboxes[CboxAmount - 1] = newCBox(-22.85, 3.96, 18.279999, 3.619999, 8.6, 3.6200008);
		Cboxes[CboxAmount - 1] = newCBox(-21.45, 3.96, 27.99, 3.6200008, 8.6, 4.119999);
		Cboxes[CboxAmount - 1] = newCBox(-8.2, 3.96, -18.24, 3.6200004, 8.6, 3.619999);
		Cboxes[CboxAmount - 1] = newCBox(0.004999995, 3.96, -4.515, 0.81, 8.6, 0.8699999);
		Cboxes[CboxAmount - 1] = newCBox(0.004999995, 3.96, 4.535, 0.81, 8.6, 0.8699999);
		Cboxes[CboxAmount - 1] = newCBox(4.505, 3.96, 0.00999999, 0.80999994, 8.6, 0.88);
		Cboxes[CboxAmount - 1] = newCBox(-4.495, 3.96, 0.00999999, 0.80999994, 8.6, 0.88);
		Cboxes[CboxAmount - 1] = newCBox(-3.185, 3.96, -3.1799998, 0.80999994, 8.6, 0.8799999);
		Cboxes[CboxAmount - 1] = newCBox(3.195, 3.96, -3.1799998, 0.80999994, 8.6, 0.8799999);
		Cboxes[CboxAmount - 1] = newCBox(-3.185, 3.96, 3.165, 0.80999994, 8.6, 0.8699999);
		Cboxes[CboxAmount - 1] = newCBox(3.195, 3.96, 3.165, 0.80999994, 8.6, 0.8699999);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 8.68, 1.51, 8.68);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 4.98, 1.51, 10.94);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 10.94, 1.51, 4.98);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 9.9, 1.51, 7.1);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 7.1, 1.51, 9.9);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 2.86, 1.51, 11.92);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 11.92, 1.51, 2.86);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 11.56, 1.51, 4.16);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 4.16, 1.51, 11.56);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 6.24, 1.51, 10.62);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 9.32, 1.51, 7.98);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 7.98, 1.51, 9.32);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.245, 0.0, 10.62, 1.51, 6.24);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 9.96, 1.51, 9.96);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 5.74, 1.51, 12.58);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 12.58, 1.51, 5.74);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 11.38, 1.51, 8.16);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 8.16, 1.51, 11.38);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 3.3, 1.51, 13.7);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 13.7, 1.51, 3.3);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 13.3, 1.51, 4.78);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 4.78, 1.51, 13.3);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 7.16, 1.51, 12.2);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 10.72, 1.51, 9.16);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 9.16, 1.51, 10.72);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.39499998, 0.0, 12.2, 1.51, 7.16);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 11.4, 1.5, 11.4);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 6.56, 1.5, 14.38);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 14.38, 1.5, 6.56);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 13.0, 1.5, 9.32);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 9.32, 1.5, 13.0);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 3.76, 1.5, 15.66);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 15.66, 1.5, 3.76);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 15.2, 1.5, 5.46);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 5.46, 1.5, 15.2);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 8.2, 1.5, 13.96);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 12.26, 1.5, 10.48);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 10.48, 1.5, 12.26);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -0.57000005, 0.0, 13.96, 1.5, 8.2);

	}





	// LV 0 Hub world
	if (currentLevel == 0) {

		// hub map walls
		Cboxes[CboxAmount - 1] = newCBox(129, 0.0, 0.0, 2, 20, 300);
		Cboxes[CboxAmount - 1] = newCBox(-129, 0.0, 0.0, 2, 20, 300);
		Cboxes[CboxAmount - 1] = newCBox(0.0, 0.0, 129, 300, 20, 2);
		Cboxes[CboxAmount - 1] = newCBox(0.0, 0.0, -129, 300, 20, 2);


		// portals
		Cboxes[CboxAmount - 1] = newCBox(-20, -3.2, 10, 1.9829, 20, 6.42671);
		Cboxes[CboxAmount - 1] = newCBox(-20, -3.2, -10, 1.9829, 20, 6.42671);
		Cboxes[CboxAmount - 1] = newCBox(-28, -4.2, 0, 1.9829, 20, 6.42671);

	}


	// LV 1 Platforms
	if (currentLevel == 1) {

		// portal collider
		Cboxes[CboxAmount - 1] = newCBox(-1.0f, 30.0f, 41.0f, 6.42671, 20, 1.9829);


		Cboxes[CboxAmount - 1] = newCBox(0.0, -26.5, 0.0, 16.0, 53.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -22.5, 19.0, 16.0, 61.0, 22.0);
		Cboxes[CboxAmount - 1] = newCBox(0.0, -22.5, -19.0, 16.0, 61.0, 22.0);
		Cboxes[CboxAmount - 1] = newCBox(20.0, -22.5, 0.0, 24.0, 61.0, 60.0);
		Cboxes[CboxAmount - 1] = newCBox(-12.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-18.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-24.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-30.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-36.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-42.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-48.0, -2.0, 0.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-68.5, -26.5, 0.0, 33.0, 53.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-77.0, 0.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 1.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-79.0, 2.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-80.0, 3.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-81.0, 4.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-82.0, 5.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-83.0, 6.5, 0.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-83.5, 7.5, 0.0, 15.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-84.0, 8.5, 0.0, 14.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-84.5, 9.5, 0.0, 13.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 8.0, -11.0, 16.0, 4.0, 38.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 10.5, -19.0, 16.0, 1.0, 22.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 11.5, -19.5, 16.0, 1.0, 21.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 12.5, -20.0, 16.0, 1.0, 20.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 13.5, -20.5, 16.0, 1.0, 19.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 14.5, -21.0, 16.0, 1.0, 18.0);

		/*
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 16.0, -21.5, 16.0, 2.0, 17.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 17.0, -22.0, 16.0, 2.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 18.0, -22.5, 16.0, 2.0, 15.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 19.0, -23.0, 16.0, 2.0, 14.0);
		Cboxes[CboxAmount - 1] = newCBox(-88.0, -16.5, -31.5, 38.0, 73.0, 29.0);
		*/
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 15.5, -21.5, 16.0, 1.0, 17.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 16.5, -22.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 17.5, -22.5, 16.0, 1.0, 15.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 18.5, -23.0, 16.0, 1.0, 14.0);
		Cboxes[CboxAmount - 1] = newCBox(-99.0, 19.5, -24.0, 16.0, 1.0, 14.0);
		//Cboxes[CboxAmount - 1] = newCBox(-88.0, -16.5, -38.0, 38.0, 73.0, 29.0);

		/*
		Cboxes[CboxAmount - 1] = newCBox(-88.0, 20.5, -38.0, 38.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-80.0, 21.5, -38.0, 22.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-79.5, 22.5, -38.0, 21.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-79.0, 23.5, -38.0, 20.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.5, 24.5, -38.0, 19.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 25.5, -38.0, 18.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-77.5, 26.5, -38.0, 17.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-77.0, 27.5, -38.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-76.5, 28.5, -38.0, 15.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-76.0, 29.5, -38.0, 14.0, 1.0, 16.0);
		*/

		Cboxes[CboxAmount - 1] = newCBox(-88.0, 19.5, -38.0, 38.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-80.0, 20.5, -38.0, 22.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-79.5, 21.5, -38.0, 21.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-79.0, 22.5, -38.0, 20.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.5, 23.5, -38.0, 19.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 24.5, -38.0, 18.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-77.5, 25.5, -38.0, 17.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-77.0, 26.5, -38.0, 16.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-76.5, 27.5, -38.0, 15.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-76.0, 28.5, -38.0, 14.0, 1.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-75.0, 29.5, -38.0, 14.0, 1.0, 16.0);

		//Cboxes[CboxAmount - 1] = newCBox(-88.0, 22.5, -38.0, 38.0, 15.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-18.5, -11.5, -38.0, 101.0, 83.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-1.0, -11.5, 38.0, 16.0, 83.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(2.0, 28.0, 26.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(6.0, 28.0, 20.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(9.0, 28.0, 14.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(10.0, 28.0, 8.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(10.0, 28.0, 0.0, 8.0, 4.0, 8.0);
		Cboxes[CboxAmount - 1] = newCBox(10.0, 28.0, -8.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(9.0, 28.0, -14.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(6.0, 28.0, -20.0, 4.0, 4.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(2.0, 28.0, -26.0, 4.0, 4.0, 4.0);

	}





	// Level 2 platforms
	if (currentLevel == 2) {

		Cboxes[CboxAmount - 1] = newCBox(-11.0f, 5.77f, -75.0f, 1.9829, 20, 6.42671);

		Cboxes[CboxAmount - 1] = newCBox(51.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(55.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(59.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(63.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(67.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(71.0, 0.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -27.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -31.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -35.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -39.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -43.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-78.0, 5.0, -47.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-50.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-54.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-58.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-62.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-66.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-70.0, -1.0, 0.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(31.724998, -0.8100004, -9.02, 31.749998, 31.62, 12.04);
		Cboxes[CboxAmount - 1] = newCBox(0.16499996, -0.8100004, 15.495001, 31.43, 31.62, 1.71);
		Cboxes[CboxAmount - 1] = newCBox(-21.145, -0.8100004, -29.73, 36.29, 31.62, 29.400002);
		Cboxes[CboxAmount - 1] = newCBox(31.724998, -7.96, -0.68499994, 31.749998, 15.92, 10.75);
		Cboxes[CboxAmount - 1] = newCBox(31.724998, -0.8100004, 9.635, 31.749998, 31.62, 13.27);
		Cboxes[CboxAmount - 1] = newCBox(-31.455002, -7.91, -0.49, 31.750002, 15.82, 10.780001);
		Cboxes[CboxAmount - 1] = newCBox(-31.455002, -0.8100004, 9.64, 31.750002, 31.62, 13.280001);
		Cboxes[CboxAmount - 1] = newCBox(20.675, -0.8100004, -29.73, 35.35, 31.62, 29.400002);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 1.11, -25.05, 6.44, 0.9200001, 10.940001);
		Cboxes[CboxAmount - 1] = newCBox(-31.455002, -0.8100004, -9.035, 31.750002, 31.62, 12.07);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 3.865, -27.22, 6.44, 0.9299998, 10.939999);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 2.95, -26.545, 6.44, 0.9200001, 10.950001);
		Cboxes[CboxAmount - 1] = newCBox(0.29500008, -8.06, -0.24499989, 31.75, 16.12, 29.39);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 3.87, -38.485, 6.44, 0.91999984, 11.889999);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 2.02, -25.73, 6.44, 0.9200001, 10.940001);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, -0.575, -20.41, 6.44, 1.15, 10.94);
		Cboxes[CboxAmount - 1] = newCBox(0.22000003, 0.20000002, -24.380001, 6.44, 0.92, 10.940001);
		Cboxes[CboxAmount - 1] = newCBox(-47.04, 4.65, -72.93, 2.2799988, 2.28, 2.2799988);
		Cboxes[CboxAmount - 1] = newCBox(-42.03, 4.65, -74.18, 2.2799988, 2.28, 2.2799988);
		Cboxes[CboxAmount - 1] = newCBox(-24.415, 4.65, -74.94, 32.93, 2.28, 13.700005);
		Cboxes[CboxAmount - 1] = newCBox(-51.93, 4.65, -70.435, 2.2799988, 2.28, 2.2699966);
		Cboxes[CboxAmount - 1] = newCBox(-56.559998, 4.65, -69.34, 2.2800026, 2.28, 2.2800064);
		Cboxes[CboxAmount - 1] = newCBox(-58.25, 4.65, -64.770004, 2.2799988, 2.28, 2.2800026);
		Cboxes[CboxAmount - 1] = newCBox(-60.64, 4.65, -60.37, 2.2799988, 2.28, 2.2799988);
		Cboxes[CboxAmount - 1] = newCBox(-75.505005, 4.65, -56.949997, 14.290001, 2.28, 13.700001);
		Cboxes[CboxAmount - 1] = newCBox(-64.91, 4.65, -57.5, 2.2800026, 2.28, 2.2799988);
		Cboxes[CboxAmount - 1] = newCBox(-77.755005, 4.965, -17.295, 9.43, 1.4500003, 13.150001);
		Cboxes[CboxAmount - 1] = newCBox(-77.755005, 3.505, -15.385, 9.43, 1.45, 13.149999);
		Cboxes[CboxAmount - 1] = newCBox(-77.755005, 2.065, -13.46, 9.43, 1.4499999, 13.140001);
		Cboxes[CboxAmount - 1] = newCBox(-77.755005, 0.68, -11.495, 9.43, 1.4599999, 13.15);
		Cboxes[CboxAmount - 1] = newCBox(-77.755005, -1.16, -0.37000012, 9.43, 2.28, 13.139999);
		Cboxes[CboxAmount - 1] = newCBox(87.56, 6.7200003, -1.19, 0.8199997, 16.56, 11.7);
		Cboxes[CboxAmount - 1] = newCBox(81.100006, 6.7200003, -6.56, 12.120003, 16.56, 0.96000004);
		Cboxes[CboxAmount - 1] = newCBox(81.009995, -0.715, -0.56500006, 12.239998, 0.90999997, 10.75);
		Cboxes[CboxAmount - 1] = newCBox(81.515, 6.7200003, 5.13, 12.949997, 16.56, 0.96000004);
		Cboxes[CboxAmount - 1] = newCBox(6.445, 9.015, -50.394997, 0.8299999, 11.97, 11.91);
		Cboxes[CboxAmount - 1] = newCBox(-6.71, 9.015, -50.394997, 0.8199997, 11.97, 11.91);
		Cboxes[CboxAmount - 1] = newCBox(-0.119999886, 9.015, -55.87, 12.34, 11.97, 0.9599991);
		Cboxes[CboxAmount - 1] = newCBox(-0.099999905, 3.875, -49.83, 12.24, 0.90999985, 10.84);

	}



	if (currentLevel == 3) {

		Cboxes[CboxAmount - 1] = newCBox(-256.0f, 64.0f, -4.0f, 6.42671, 20, 1.9829);

		Cboxes[CboxAmount - 1] = newCBox(0.0, -26.5, 0.0, 16.0, 53.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-64.0, -26.5, 0.0, 16.0, 53.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, -2.5, 24.0, 16.0, 101.0, 64.0);
		Cboxes[CboxAmount - 1] = newCBox(-64.0, -16.5, -64.0, 16.0, 73.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, -2.5, -64.0, 16.0, 101.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-192.0, -2.5, 0.0, 16.0, 101.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-133.5, 56.0, 31.0, 5.0, 16.0, 50.0);
		Cboxes[CboxAmount - 1] = newCBox(-122.5, 56.0, 31.0, 5.0, 16.0, 50.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 14.0, 64.0, 16.0, 134.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 49.0, 42.0, 6.0, 2.0, 28.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 51.0, 44.0, 6.0, 2.0, 24.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 53.0, 46.0, 6.0, 2.0, 20.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 55.0, 48.0, 6.0, 2.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 57.0, 50.0, 6.0, 2.0, 12.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 59.0, 52.0, 6.0, 2.0, 8.0);
		Cboxes[CboxAmount - 1] = newCBox(-128.0, 61.0, 54.0, 6.0, 2.0, 4.0);
		Cboxes[CboxAmount - 1] = newCBox(-133.5, 69.0, 25.0, 5.0, 10.0, 38.0);
		Cboxes[CboxAmount - 1] = newCBox(-122.5, 69.0, 31.0, 5.0, 10.0, 50.0);
		Cboxes[CboxAmount - 1] = newCBox(-192.0, 63.0, 50.0, 112.0, 2.0, 12.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 5.5, 0.0, 16.0, 117.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 5.5, 50.0, 16.0, 117.0, 16.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 39.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 35.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 31.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 27.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 23.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 19.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 15.0, 2.0, 2.0, 2.0);
		Cboxes[CboxAmount - 1] = newCBox(-256.0, 63.0, 11.0, 2.0, 2.0, 2.0);

		

	}

}

void actionCBoxes() {
	if (buttons[13].toggle == true) {
		if (creativeMode == 2) {
			Cboxes[CboxAmount - 1].x = (int)((camx + sin(camAngY) * 3) * 4) / 4.0;
			Cboxes[CboxAmount - 1].y = (int)((camy + sin(camAngX) * 3) * 8) / 8.0;
			Cboxes[CboxAmount - 1].z = (int)((camz - cos(camAngY) * 3) * 4) / 4.0;

			if (mouseRDown == true && mouseRWait == false) {
				Cboxes[CboxAmount - 1] = newCBox((int)((camx + sin(camAngY) * 3) * 4) / 4.0, (int)((camy + sin(camAngX) * 3) * 8) / 8.0, (int)((camz - cos(camAngY) * 3) * 4) / 4.0, 1, 1, 1);
				mouseRWait = true;
			}
			if (mouseRDown == false) {
				mouseRWait = false;
			}
		}
		else {
		}
		//setMaterialAdvanced(materialCollisionBox);
		for (int i = 0; i < CboxAmount; i++) {
			// Do not render collision boxes
			//objPlacementTRS(drawBox, Cboxes[i].x, Cboxes[i].y, Cboxes[i].z, 0.0, 0.0, 0.0, Cboxes[i].sx, Cboxes[i].sy, Cboxes[i].sz);
			if (camx > Cboxes[i].x - playerSize - Cboxes[i].sx / 2 && camx < Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
				if (camy > Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && camy < Cboxes[i].y + playerHeight + Cboxes[i].sy / 2) {
					if (camz > Cboxes[i].z - playerSize - Cboxes[i].sz / 2 && camz < Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {

						if (ox >= Cboxes[i].x - playerSize - Cboxes[i].sx / 2 || ox <= Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
							if (oz >= Cboxes[i].z - playerSize - Cboxes[i].sz / 2 || oz <= Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
								if (oy <= Cboxes[i].y - playerSize + 0.2 - Cboxes[i].sy / 2) {
									camy = Cboxes[i].y - playerSize - Cboxes[i].sy / 2;
									//oy = y;
								}
								if (oy >= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
									camy = Cboxes[i].y + playerHeight + Cboxes[i].sy / 2;
									//oy = y;
									camyv = 0.0f;
									jumpFrame = 0;
									canJump = true;
								}
							}
						}

						if (ox >= Cboxes[i].x - playerSize - Cboxes[i].sx / 2 || ox <= Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
							if (oy >= Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && oy <= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
								if (oz <= Cboxes[i].z - playerSize - Cboxes[i].sz / 2) {
									camz = Cboxes[i].z - playerSize - Cboxes[i].sz / 2;
									//oz = z;
								}
								if (oz >= Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
									camz = Cboxes[i].z + playerSize + Cboxes[i].sz / 2;
									//oz = z;
								}
							}
						}


						if (oz >= Cboxes[i].z - playerSize - Cboxes[i].sz / 2 || oz <= Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
							if (oy >= Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && oy <= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
								if (ox <= Cboxes[i].x - playerSize - Cboxes[i].sx / 2) {
									camx = Cboxes[i].x - playerSize - Cboxes[i].sx / 2;
									//ox = x;
								}
								if (ox >= Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
									camx = Cboxes[i].x + playerSize + Cboxes[i].sx / 2;
									//ox = x;
								}
							}
						}



					}
				}
			}
		}
	}
}