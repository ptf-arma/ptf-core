		maxSpeed = 1000;
		landingAoa = 0.139626; // 8 deg
		landingSpeed = 260;
		vtol = 1;

		stallSpeed = 220;
		stallWarningTreshold = 0.12;
		altFullForce = 2000;
		altNoForce = 16000;

		airBrake = 1;
		flaps = 1;
		airBrakeFrictionCoef = 5.0;
		flapsFrictionCoef = 0.37;
		gearsUpFrictionCoef = 0.8;

		elevatorControlsSensitivityCoef = 4.0;
		aileronControlsSensitivityCoef = 4.0;
		rudderControlsSensitivityCoef = 2.0;
		wheelSteeringSensitivity = 3.5;
		elevatorSensitivity = 0.480;
		aileronSensitivity = 0.680;
		rudderInfluence = 0.240;

		airFrictionCoefs0[] = {0, 0, 0};
		airFrictionCoefs1[] = {0.01, 0.04, 0.012};
		airFrictionCoefs2[] = {0.001, 0.004, 0.000015};
		draconicForceXCoef = 7.0;
		draconicForceYCoef = 1.1;
		draconicForceZCoef = 1.0;
		draconicTorqueXCoef[] = {4, 3.92, 3.8, 3.6, 3.36, 3.12, 3, 4, 7.6, 6};
		draconicTorqueYCoef[] = {6.5, 3.0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		angleOfIndicence = 0.0523599; // 3 deg
		envelope[] = {0, 0.3, 0.9, 1.8, 2.6, 3.2, 3.6, 3.8, 3.9, 3.7, 3.4};
		aileronCoef[] = {1, 1.6, 1.8, 1.88, 1.9, 1.85, 1.75, 1.6, 1.4, 1.2, 1.058};
		elevatorCoef[] = {1, 1.55, 1.7, 1.65, 1.55, 1.4, 1.2, 1, 0.8, 0.65, 0.55};
		rudderCoef[] = {1, 1.55, 1.7, 1.65, 1.55, 1.4, 1.2, 1, 0.8, 0.65, 0.55};
				fuelCapacity = 492.3;
		thrustCoef[] = {
			2.1157723917440974,
			2.0175180720108750,
			1.9327461835953060,
			1.8590774739119210,
			1.7941326903752532,
			1.7355325803998336,
			1.6808978914001944,
			1.6278493707908670,
			1.5740077659863836,
			1.5169938244012764,
			1.4544282934500763,
			1.3839319205473157,
			1.3031254531075270,
			1.2096296385452405,
			1.1010652242749897,
			0.9750529577113052,
			0.8292135862687195,
			0.6611678573617646,
			0.4685365184049714,
			0.2489403168128729,
			0
		};