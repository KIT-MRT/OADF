## **********************************************************************
## FileCreator 	CarMaker/Vehicle Data Set Generator 2018-07-27 10:42:17
## FileName 	AUTOelfe.tcl
## Description: Generated - not validated - Compact Car
## 		FileCreator CarMaker/Vehicle Data Set Generator 2018-07-27 10:42:17
## 		driveline fourwheel drive
## 		engine power 81.0 kW (110 PS) at 6000.0 rpm
## 		max. torque 152.0 Nm at 4000.0 rpm
## 		unloaded weight 2300.0 kg
## 		length x width x height 4760.0 mm x 2000.0 mm x 1445.0 mm
## 		wheel base 3100.0 mm
## 		track width front 1800.0 mm
## 		track width rear 1800.0 mm
## 		rear overhang 830.0 mm
## 		tire 155/70 R19
## **********************************************************************
proc DefineCarTop {cv {col gray} {ShowDetails 0}} {
    $cv create rectangle 48.0 81.45 118.0 96.95 -fill gray -outline gray -tag tire
    $cv create rectangle 48.0 -96.95 118.0 -81.45 -fill gray -outline gray -tag tire
    $cv create rectangle 358.0 81.85 428.0 97.35 -fill gray -outline gray -tag tire
    $cv create rectangle 358.0 -97.35 428.0 -81.85 -fill gray -outline gray -tag tire
    $cv create line 41.15 96.95 37.721 96.896 -fill $col 
    $cv create line 37.721 96.896 34.292 96.735 -fill $col 
    $cv create line 34.292 96.735 30.862 96.466 -fill $col 
    $cv create line 30.862 96.466 27.433 96.089 -fill $col 
    $cv create line 27.433 96.089 24.004 95.605 -fill $col 
    $cv create line 24.004 95.605 20.575 95.013 -fill $col 
    $cv create line 20.575 95.013 17.146 94.313 -fill $col 
    $cv create line 17.146 94.313 13.717 93.506 -fill $col 
    $cv create line 13.717 93.506 10.287 92.591 -fill $col 
    $cv create line 10.287 92.591 6.858 91.568 -fill $col 
    $cv create line 6.858 91.568 3.429 90.438 -fill $col 
    $cv create line 3.429 90.438 0.0 89.2 -fill $col 
    $cv create line 41.15 -96.95 37.721 -96.896 -fill $col 
    $cv create line 37.721 -96.896 34.292 -96.735 -fill $col 
    $cv create line 34.292 -96.735 30.862 -96.466 -fill $col 
    $cv create line 30.862 -96.466 27.433 -96.089 -fill $col 
    $cv create line 27.433 -96.089 24.004 -95.605 -fill $col 
    $cv create line 24.004 -95.605 20.575 -95.013 -fill $col 
    $cv create line 20.575 -95.013 17.146 -94.313 -fill $col 
    $cv create line 17.146 -94.313 13.717 -93.506 -fill $col 
    $cv create line 13.717 -93.506 10.287 -92.591 -fill $col 
    $cv create line 10.287 -92.591 6.858 -91.568 -fill $col 
    $cv create line 6.858 -91.568 3.429 -90.438 -fill $col 
    $cv create line 3.429 -90.438 0.0 -89.2 -fill $col 
    $cv create line 41.15 96.95 124.8 96.95 -fill $col 
    $cv create line 41.15 -96.95 124.8 -96.95 -fill $col 
    $cv create line 124.8 96.95 351.2 97.35 -fill $col 
    $cv create line 124.8 -96.95 351.2 -97.35 -fill $col 
    $cv create line 351.2 97.35 434.85 97.35 -fill $col 
    $cv create line 351.2 -97.35 434.85 -97.35 -fill $col 
    $cv create line 434.85 97.35 438.28 97.296 -fill $col 
    $cv create line 438.28 97.296 441.71 97.135 -fill $col 
    $cv create line 441.71 97.135 445.14 96.866 -fill $col 
    $cv create line 445.14 96.866 448.57 96.489 -fill $col 
    $cv create line 448.57 96.489 452.0 96.005 -fill $col 
    $cv create line 452.0 96.005 455.43 95.413 -fill $col 
    $cv create line 455.43 95.413 458.85 94.713 -fill $col 
    $cv create line 458.85 94.713 462.28 93.906 -fill $col 
    $cv create line 462.28 93.906 465.71 92.991 -fill $col 
    $cv create line 465.71 92.991 469.14 91.968 -fill $col 
    $cv create line 469.14 91.968 472.57 90.838 -fill $col 
    $cv create line 472.57 90.838 476.0 89.6 -fill $col 
    $cv create line 434.85 -97.35 438.28 -97.296 -fill $col 
    $cv create line 438.28 -97.296 441.71 -97.135 -fill $col 
    $cv create line 441.71 -97.135 445.14 -96.866 -fill $col 
    $cv create line 445.14 -96.866 448.57 -96.489 -fill $col 
    $cv create line 448.57 -96.489 452.0 -96.005 -fill $col 
    $cv create line 452.0 -96.005 455.43 -95.413 -fill $col 
    $cv create line 455.43 -95.413 458.85 -94.713 -fill $col 
    $cv create line 458.85 -94.713 462.28 -93.906 -fill $col 
    $cv create line 462.28 -93.906 465.71 -92.991 -fill $col 
    $cv create line 465.71 -92.991 469.14 -91.968 -fill $col 
    $cv create line 469.14 -91.968 472.57 -90.838 -fill $col 
    $cv create line 472.57 -90.838 476.0 -89.6 -fill $col 
    $cv create line 476.0 74.1 345.2 85.725 -fill $col 
    $cv create line 476.0 -74.1 345.2 -85.725 -fill $col 
    $cv create line 345.2 85.725 336.27 85.644 -fill $col 
    $cv create line 336.27 85.644 327.33 85.402 -fill $col 
    $cv create line 327.33 85.402 318.4 84.998 -fill $col 
    $cv create line 318.4 84.998 309.47 84.433 -fill $col 
    $cv create line 309.47 84.433 300.53 83.707 -fill $col 
    $cv create line 300.53 83.707 291.6 82.819 -fill $col 
    $cv create line 291.6 82.819 282.67 81.769 -fill $col 
    $cv create line 282.67 81.769 273.73 80.558 -fill $col 
    $cv create line 273.73 80.558 264.8 79.186 -fill $col 
    $cv create line 264.8 79.186 255.87 77.652 -fill $col 
    $cv create line 255.87 77.652 246.93 75.957 -fill $col 
    $cv create line 246.93 75.957 238.0 74.1 -fill $col 
    $cv create line 345.2 -85.725 336.27 -85.644 -fill $col 
    $cv create line 336.27 -85.644 327.33 -85.402 -fill $col 
    $cv create line 327.33 -85.402 318.4 -84.998 -fill $col 
    $cv create line 318.4 -84.998 309.47 -84.433 -fill $col 
    $cv create line 309.47 -84.433 300.53 -83.707 -fill $col 
    $cv create line 300.53 -83.707 291.6 -82.819 -fill $col 
    $cv create line 291.6 -82.819 282.67 -81.769 -fill $col 
    $cv create line 282.67 -81.769 273.73 -80.558 -fill $col 
    $cv create line 273.73 -80.558 264.8 -79.186 -fill $col 
    $cv create line 264.8 -79.186 255.87 -77.652 -fill $col 
    $cv create line 255.87 -77.652 246.93 -75.957 -fill $col 
    $cv create line 246.93 -75.957 238.0 -74.1 -fill $col 
    $cv create line 238.0 74.1 41.15 73.7 -fill $col 
    $cv create line 238.0 -74.1 41.15 -73.7 -fill $col 
    $cv create line 0.0 85.325 0.0 73.7 -fill $col 
    $cv create line 0.0 -85.325 0.0 -73.7 -fill $col 
    $cv create line 0.0 85.325 3.429 85.244 -fill $col 
    $cv create line 3.429 85.244 6.858 85.002 -fill $col 
    $cv create line 6.858 85.002 10.287 84.598 -fill $col 
    $cv create line 10.287 84.598 13.717 84.033 -fill $col 
    $cv create line 13.717 84.033 17.146 83.307 -fill $col 
    $cv create line 17.146 83.307 20.575 82.419 -fill $col 
    $cv create line 20.575 82.419 24.004 81.369 -fill $col 
    $cv create line 24.004 81.369 27.433 80.158 -fill $col 
    $cv create line 27.433 80.158 30.862 78.786 -fill $col 
    $cv create line 30.862 78.786 34.292 77.252 -fill $col 
    $cv create line 34.292 77.252 37.721 75.557 -fill $col 
    $cv create line 37.721 75.557 41.15 73.7 -fill $col 
    $cv create line 0.0 -85.325 3.429 -85.244 -fill $col 
    $cv create line 3.429 -85.244 6.858 -85.002 -fill $col 
    $cv create line 6.858 -85.002 10.287 -84.598 -fill $col 
    $cv create line 10.287 -84.598 13.717 -84.033 -fill $col 
    $cv create line 13.717 -84.033 17.146 -83.307 -fill $col 
    $cv create line 17.146 -83.307 20.575 -82.419 -fill $col 
    $cv create line 20.575 -82.419 24.004 -81.369 -fill $col 
    $cv create line 24.004 -81.369 27.433 -80.158 -fill $col 
    $cv create line 27.433 -80.158 30.862 -78.786 -fill $col 
    $cv create line 30.862 -78.786 34.292 -77.252 -fill $col 
    $cv create line 34.292 -77.252 37.721 -75.557 -fill $col 
    $cv create line 37.721 -75.557 41.15 -73.7 -fill $col 
    $cv create line 476.0 89.6 477.0 88.978 -fill $col 
    $cv create line 477.0 88.978 478.0 87.111 -fill $col 
    $cv create line 478.0 87.111 479.0 84.0 -fill $col 
    $cv create line 479.0 84.0 480.0 79.644 -fill $col 
    $cv create line 480.0 79.644 481.0 74.044 -fill $col 
    $cv create line 481.0 74.044 482.0 67.2 -fill $col 
    $cv create line 482.0 67.2 483.0 59.111 -fill $col 
    $cv create line 483.0 59.111 484.0 49.778 -fill $col 
    $cv create line 484.0 49.778 485.0 39.2 -fill $col 
    $cv create line 485.0 39.2 486.0 27.378 -fill $col 
    $cv create line 486.0 27.378 487.0 14.311 -fill $col 
    $cv create line 487.0 14.311 488.0 -0.0 -fill $col 
    $cv create line 476.0 -89.6 477.0 -88.978 -fill $col 
    $cv create line 477.0 -88.978 478.0 -87.111 -fill $col 
    $cv create line 478.0 -87.111 479.0 -84.0 -fill $col 
    $cv create line 479.0 -84.0 480.0 -79.644 -fill $col 
    $cv create line 480.0 -79.644 481.0 -74.044 -fill $col 
    $cv create line 481.0 -74.044 482.0 -67.2 -fill $col 
    $cv create line 482.0 -67.2 483.0 -59.111 -fill $col 
    $cv create line 483.0 -59.111 484.0 -49.778 -fill $col 
    $cv create line 484.0 -49.778 485.0 -39.2 -fill $col 
    $cv create line 485.0 -39.2 486.0 -27.378 -fill $col 
    $cv create line 486.0 -27.378 487.0 -14.311 -fill $col 
    $cv create line 487.0 -14.311 488.0 0.0 -fill $col 
    $cv create line 476.0 74.1 476.67 73.585 -fill $col 
    $cv create line 476.67 73.585 477.33 72.042 -fill $col 
    $cv create line 477.33 72.042 478.0 69.469 -fill $col 
    $cv create line 478.0 69.469 478.67 65.867 -fill $col 
    $cv create line 478.67 65.867 479.33 61.235 -fill $col 
    $cv create line 479.33 61.235 480.0 55.575 -fill $col 
    $cv create line 480.0 55.575 480.67 48.885 -fill $col 
    $cv create line 480.67 48.885 481.33 41.167 -fill $col 
    $cv create line 481.33 41.167 482.0 32.419 -fill $col 
    $cv create line 482.0 32.419 482.67 22.642 -fill $col 
    $cv create line 482.67 22.642 483.33 11.835 -fill $col 
    $cv create line 483.33 11.835 484.0 0.0 -fill $col 
    $cv create line 476.0 -74.1 476.67 -73.585 -fill $col 
    $cv create line 476.67 -73.585 477.33 -72.042 -fill $col 
    $cv create line 477.33 -72.042 478.0 -69.469 -fill $col 
    $cv create line 478.0 -69.469 478.67 -65.867 -fill $col 
    $cv create line 478.67 -65.867 479.33 -61.235 -fill $col 
    $cv create line 479.33 -61.235 480.0 -55.575 -fill $col 
    $cv create line 480.0 -55.575 480.67 -48.885 -fill $col 
    $cv create line 480.67 -48.885 481.33 -41.167 -fill $col 
    $cv create line 481.33 -41.167 482.0 -32.419 -fill $col 
    $cv create line 482.0 -32.419 482.67 -22.642 -fill $col 
    $cv create line 482.67 -22.642 483.33 -11.835 -fill $col 
    $cv create line 483.33 -11.835 484.0 0.0 -fill $col 
    $cv create line 345.2 85.725 346.2 85.13 -fill $col 
    $cv create line 346.2 85.13 347.2 83.344 -fill $col 
    $cv create line 347.2 83.344 348.2 80.367 -fill $col 
    $cv create line 348.2 80.367 349.2 76.2 -fill $col 
    $cv create line 349.2 76.2 350.2 70.842 -fill $col 
    $cv create line 350.2 70.842 351.2 64.294 -fill $col 
    $cv create line 351.2 64.294 352.2 56.555 -fill $col 
    $cv create line 352.2 56.555 353.2 47.625 -fill $col 
    $cv create line 353.2 47.625 354.2 37.505 -fill $col 
    $cv create line 354.2 37.505 355.2 26.194 -fill $col 
    $cv create line 355.2 26.194 356.2 13.692 -fill $col 
    $cv create line 356.2 13.692 357.2 0.0 -fill $col 
    $cv create line 345.2 -85.725 346.2 -85.13 -fill $col 
    $cv create line 346.2 -85.13 347.2 -83.344 -fill $col 
    $cv create line 347.2 -83.344 348.2 -80.367 -fill $col 
    $cv create line 348.2 -80.367 349.2 -76.2 -fill $col 
    $cv create line 349.2 -76.2 350.2 -70.842 -fill $col 
    $cv create line 350.2 -70.842 351.2 -64.294 -fill $col 
    $cv create line 351.2 -64.294 352.2 -56.555 -fill $col 
    $cv create line 352.2 -56.555 353.2 -47.625 -fill $col 
    $cv create line 353.2 -47.625 354.2 -37.505 -fill $col 
    $cv create line 354.2 -37.505 355.2 -26.194 -fill $col 
    $cv create line 355.2 -26.194 356.2 -13.692 -fill $col 
    $cv create line 356.2 -13.692 357.2 0.0 -fill $col 
    $cv create line 238.0 74.1 238.83 73.585 -fill $col 
    $cv create line 238.83 73.585 239.67 72.042 -fill $col 
    $cv create line 239.67 72.042 240.5 69.469 -fill $col 
    $cv create line 240.5 69.469 241.33 65.867 -fill $col 
    $cv create line 241.33 65.867 242.17 61.235 -fill $col 
    $cv create line 242.17 61.235 243.0 55.575 -fill $col 
    $cv create line 243.0 55.575 243.83 48.885 -fill $col 
    $cv create line 243.83 48.885 244.67 41.167 -fill $col 
    $cv create line 244.67 41.167 245.5 32.419 -fill $col 
    $cv create line 245.5 32.419 246.33 22.642 -fill $col 
    $cv create line 246.33 22.642 247.17 11.835 -fill $col 
    $cv create line 247.17 11.835 248.0 0.0 -fill $col 
    $cv create line 238.0 -74.1 238.83 -73.585 -fill $col 
    $cv create line 238.83 -73.585 239.67 -72.042 -fill $col 
    $cv create line 239.67 -72.042 240.5 -69.469 -fill $col 
    $cv create line 240.5 -69.469 241.33 -65.867 -fill $col 
    $cv create line 241.33 -65.867 242.17 -61.235 -fill $col 
    $cv create line 242.17 -61.235 243.0 -55.575 -fill $col 
    $cv create line 243.0 -55.575 243.83 -48.885 -fill $col 
    $cv create line 243.83 -48.885 244.67 -41.167 -fill $col 
    $cv create line 244.67 -41.167 245.5 -32.419 -fill $col 
    $cv create line 245.5 -32.419 246.33 -22.642 -fill $col 
    $cv create line 246.33 -22.642 247.17 -11.835 -fill $col 
    $cv create line 247.17 -11.835 248.0 -0.0 -fill $col 
    $cv create line 41.15 73.7 40.317 73.188 -fill $col 
    $cv create line 40.317 73.188 39.483 71.653 -fill $col 
    $cv create line 39.483 71.653 38.65 69.094 -fill $col 
    $cv create line 38.65 69.094 37.817 65.511 -fill $col 
    $cv create line 37.817 65.511 36.983 60.905 -fill $col 
    $cv create line 36.983 60.905 36.15 55.275 -fill $col 
    $cv create line 36.15 55.275 35.317 48.622 -fill $col 
    $cv create line 35.317 48.622 34.483 40.944 -fill $col 
    $cv create line 34.483 40.944 33.65 32.244 -fill $col 
    $cv create line 33.65 32.244 32.817 22.519 -fill $col 
    $cv create line 32.817 22.519 31.983 11.772 -fill $col 
    $cv create line 31.983 11.772 31.15 0.0 -fill $col 
    $cv create line 41.15 -73.7 40.317 -73.188 -fill $col 
    $cv create line 40.317 -73.188 39.483 -71.653 -fill $col 
    $cv create line 39.483 -71.653 38.65 -69.094 -fill $col 
    $cv create line 38.65 -69.094 37.817 -65.511 -fill $col 
    $cv create line 37.817 -65.511 36.983 -60.905 -fill $col 
    $cv create line 36.983 -60.905 36.15 -55.275 -fill $col 
    $cv create line 36.15 -55.275 35.317 -48.622 -fill $col 
    $cv create line 35.317 -48.622 34.483 -40.944 -fill $col 
    $cv create line 34.483 -40.944 33.65 -32.244 -fill $col 
    $cv create line 33.65 -32.244 32.817 -22.519 -fill $col 
    $cv create line 32.817 -22.519 31.983 -11.772 -fill $col 
    $cv create line 31.983 -11.772 31.15 0.0 -fill $col 
    $cv create line 4.0 85.325 3.167 84.732 -fill $col 
    $cv create line 3.167 84.732 2.333 82.955 -fill $col 
    $cv create line 2.333 82.955 1.5 79.992 -fill $col 
    $cv create line 1.5 79.992 0.667 75.844 -fill $col 
    $cv create line 0.667 75.844 -0.167 70.512 -fill $col 
    $cv create line -0.167 70.512 -1.0 63.994 -fill $col 
    $cv create line -1.0 63.994 -1.833 56.291 -fill $col 
    $cv create line -1.833 56.291 -2.667 47.403 -fill $col 
    $cv create line -2.667 47.403 -3.5 37.33 -fill $col 
    $cv create line -3.5 37.33 -4.333 26.072 -fill $col 
    $cv create line -4.333 26.072 -5.167 13.628 -fill $col 
    $cv create line -5.167 13.628 -6.0 0.0 -fill $col 
    $cv create line 4.0 -85.325 3.167 -84.732 -fill $col 
    $cv create line 3.167 -84.732 2.333 -82.955 -fill $col 
    $cv create line 2.333 -82.955 1.5 -79.992 -fill $col 
    $cv create line 1.5 -79.992 0.667 -75.844 -fill $col 
    $cv create line 0.667 -75.844 -0.167 -70.512 -fill $col 
    $cv create line -0.167 -70.512 -1.0 -63.994 -fill $col 
    $cv create line -1.0 -63.994 -1.833 -56.291 -fill $col 
    $cv create line -1.833 -56.291 -2.667 -47.403 -fill $col 
    $cv create line -2.667 -47.403 -3.5 -37.33 -fill $col 
    $cv create line -3.5 -37.33 -4.333 -26.072 -fill $col 
    $cv create line -4.333 -26.072 -5.167 -13.628 -fill $col 
    $cv create line -5.167 -13.628 -6.0 0.0 -fill $col 
    $cv create line 4.0 73.7 3.167 73.188 -fill $col 
    $cv create line 3.167 73.188 2.333 71.653 -fill $col 
    $cv create line 2.333 71.653 1.5 69.094 -fill $col 
    $cv create line 1.5 69.094 0.667 65.511 -fill $col 
    $cv create line 0.667 65.511 -0.167 60.905 -fill $col 
    $cv create line -0.167 60.905 -1.0 55.275 -fill $col 
    $cv create line -1.0 55.275 -1.833 48.622 -fill $col 
    $cv create line -1.833 48.622 -2.667 40.944 -fill $col 
    $cv create line -2.667 40.944 -3.5 32.244 -fill $col 
    $cv create line -3.5 32.244 -4.333 22.519 -fill $col 
    $cv create line -4.333 22.519 -5.167 11.772 -fill $col 
    $cv create line -5.167 11.772 -6.0 0.0 -fill $col 
    $cv create line 4.0 -73.7 3.167 -73.188 -fill $col 
    $cv create line 3.167 -73.188 2.333 -71.653 -fill $col 
    $cv create line 2.333 -71.653 1.5 -69.094 -fill $col 
    $cv create line 1.5 -69.094 0.667 -65.511 -fill $col 
    $cv create line 0.667 -65.511 -0.167 -60.905 -fill $col 
    $cv create line -0.167 -60.905 -1.0 -55.275 -fill $col 
    $cv create line -1.0 -55.275 -1.833 -48.622 -fill $col 
    $cv create line -1.833 -48.622 -2.667 -40.944 -fill $col 
    $cv create line -2.667 -40.944 -3.5 -32.244 -fill $col 
    $cv create line -3.5 -32.244 -4.333 -22.519 -fill $col 
    $cv create line -4.333 -22.519 -5.167 -11.772 -fill $col 
    $cv create line -5.167 -11.772 -6.0 0.0 -fill $col 
    $cv create line 2.0 89.2 1.167 88.581 -fill $col 
    $cv create line 1.167 88.581 0.333 86.722 -fill $col 
    $cv create line 0.333 86.722 -0.5 83.625 -fill $col 
    $cv create line -0.5 83.625 -1.333 79.289 -fill $col 
    $cv create line -1.333 79.289 -2.167 73.714 -fill $col 
    $cv create line -2.167 73.714 -3.0 66.9 -fill $col 
    $cv create line -3.0 66.9 -3.833 58.847 -fill $col 
    $cv create line -3.833 58.847 -4.667 49.556 -fill $col 
    $cv create line -4.667 49.556 -5.5 39.025 -fill $col 
    $cv create line -5.5 39.025 -6.333 27.256 -fill $col 
    $cv create line -6.333 27.256 -7.167 14.247 -fill $col 
    $cv create line -7.167 14.247 -8.0 0.0 -fill $col 
    $cv create line 2.0 -89.2 1.167 -88.581 -fill $col 
    $cv create line 1.167 -88.581 0.333 -86.722 -fill $col 
    $cv create line 0.333 -86.722 -0.5 -83.625 -fill $col 
    $cv create line -0.5 -83.625 -1.333 -79.289 -fill $col 
    $cv create line -1.333 -79.289 -2.167 -73.714 -fill $col 
    $cv create line -2.167 -73.714 -3.0 -66.9 -fill $col 
    $cv create line -3.0 -66.9 -3.833 -58.847 -fill $col 
    $cv create line -3.833 -58.847 -4.667 -49.556 -fill $col 
    $cv create line -4.667 -49.556 -5.5 -39.025 -fill $col 
    $cv create line -5.5 -39.025 -6.333 -27.256 -fill $col 
    $cv create line -6.333 -27.256 -7.167 -14.247 -fill $col 
    $cv create line -7.167 -14.247 -8.0 0.0 -fill $col 
    $cv create line 25.0 91.95 167.6 92.15 -fill $col 
    $cv create line 167.6 92.15 167.6 78.9 -fill $col 
    $cv create line 167.6 78.9 46.15 78.7 -fill $col 
    $cv create line 46.15 78.7 25.0 91.95 -fill $col 
    $cv create line 25.0 -91.95 167.6 -92.15 -fill $col 
    $cv create line 167.6 -92.15 167.6 -78.9 -fill $col 
    $cv create line 167.6 -78.9 46.15 -78.7 -fill $col 
    $cv create line 46.15 -78.7 25.0 -91.95 -fill $col 
    $cv create line 177.6 92.15 325.2 92.35 -fill $col 
    $cv create line 238.0 81.1 325.2 92.35 -fill $col 
    $cv create line 238.0 81.1 177.6 78.9 -fill $col 
    $cv create line 177.6 78.9 177.6 92.15 -fill $col 
    $cv create line 177.6 -92.15 325.2 -92.35 -fill $col 
    $cv create line 238.0 -81.1 325.2 -92.35 -fill $col 
    $cv create line 238.0 -81.1 177.6 -78.9 -fill $col 
    $cv create line 177.6 -78.9 177.6 -92.15 -fill $col 
    $cv create line 172.6 96.95 172.6 73.7 -fill $col 
    $cv create line 172.6 -96.95 172.6 -73.7 -fill $col 
    $cv create line 325.2 97.35 325.2 85.725 -fill $col 
    $cv create line 325.2 -97.35 325.2 -85.725 -fill $col 
}
proc DefineCarSide {cv {col gray} {ShowDetails 0}} {
    $cv create oval 50.0 -1.1 116.0 64.9 -fill gray -outline $col
    $cv create oval 58.9 7.8 107.1 56.0 -fill white -outline $col
    $cv create oval 360.0 -1.1 426.0 64.9 -fill gray -outline $col
    $cv create oval 368.9 7.8 417.1 56.0 -fill white -outline $col
    $cv create line 17.575 31.9 16.11 32.04 -fill $col 
    $cv create line 16.11 32.04 14.646 32.46 -fill $col 
    $cv create line 14.646 32.46 13.181 33.161 -fill $col 
    $cv create line 13.181 33.161 11.717 34.142 -fill $col 
    $cv create line 11.717 34.142 10.252 35.403 -fill $col 
    $cv create line 10.252 35.403 8.787 36.944 -fill $col 
    $cv create line 8.787 36.944 7.323 38.765 -fill $col 
    $cv create line 7.323 38.765 5.858 40.867 -fill $col 
    $cv create line 5.858 40.867 4.394 43.248 -fill $col 
    $cv create line 4.394 43.248 2.929 45.91 -fill $col 
    $cv create line 2.929 45.91 1.465 48.853 -fill $col 
    $cv create line 1.465 48.853 0.0 52.075 -fill $col 
    $cv create line 17.575 31.9 41.15 31.9 -fill $col 
    $cv create line 124.8 31.9 351.2 31.9 -fill $col 
    $cv create line 434.85 31.9 441.0 31.9 -fill $col 
    $cv create line 441.0 31.9 443.92 32.04 -fill $col 
    $cv create line 443.92 32.04 446.83 32.46 -fill $col 
    $cv create line 446.83 32.46 449.75 33.161 -fill $col 
    $cv create line 449.75 33.161 452.67 34.142 -fill $col 
    $cv create line 452.67 34.142 455.58 35.403 -fill $col 
    $cv create line 455.58 35.403 458.5 36.944 -fill $col 
    $cv create line 458.5 36.944 461.42 38.765 -fill $col 
    $cv create line 461.42 38.765 464.33 40.867 -fill $col 
    $cv create line 464.33 40.867 467.25 43.248 -fill $col 
    $cv create line 467.25 43.248 470.17 45.91 -fill $col 
    $cv create line 470.17 45.91 473.08 48.853 -fill $col 
    $cv create line 473.08 48.853 476.0 52.075 -fill $col 
    $cv create line 476.0 52.075 476.0 72.25 -fill $col 
    $cv create line 345.2 96.333 356.1 96.166 -fill $col 
    $cv create line 356.1 96.166 367.0 95.664 -fill $col 
    $cv create line 367.0 95.664 377.9 94.828 -fill $col 
    $cv create line 377.9 94.828 388.8 93.657 -fill $col 
    $cv create line 388.8 93.657 399.7 92.152 -fill $col 
    $cv create line 399.7 92.152 410.6 90.312 -fill $col 
    $cv create line 410.6 90.312 421.5 88.138 -fill $col 
    $cv create line 421.5 88.138 432.4 85.63 -fill $col 
    $cv create line 432.4 85.63 443.3 82.786 -fill $col 
    $cv create line 443.3 82.786 454.2 79.609 -fill $col 
    $cv create line 454.2 79.609 465.1 76.097 -fill $col 
    $cv create line 465.1 76.097 476.0 72.25 -fill $col 
    $cv create line 238.0 144.5 246.93 144.17 -fill $col 
    $cv create line 246.93 144.17 255.87 143.16 -fill $col 
    $cv create line 255.87 143.16 264.8 141.49 -fill $col 
    $cv create line 264.8 141.49 273.73 139.15 -fill $col 
    $cv create line 273.73 139.15 282.67 136.14 -fill $col 
    $cv create line 282.67 136.14 291.6 132.46 -fill $col 
    $cv create line 291.6 132.46 300.53 128.11 -fill $col 
    $cv create line 300.53 128.11 309.47 123.09 -fill $col 
    $cv create line 309.47 123.09 318.4 117.41 -fill $col 
    $cv create line 318.4 117.41 327.33 111.05 -fill $col 
    $cv create line 327.33 111.05 336.27 104.03 -fill $col 
    $cv create line 336.27 104.03 345.2 96.333 -fill $col 
    $cv create line 238.0 144.5 41.15 144.5 -fill $col 
    $cv create line 41.15 144.5 37.721 144.17 -fill $col 
    $cv create line 37.721 144.17 34.292 143.16 -fill $col 
    $cv create line 34.292 143.16 30.862 141.49 -fill $col 
    $cv create line 30.862 141.49 27.433 139.15 -fill $col 
    $cv create line 27.433 139.15 24.004 136.14 -fill $col 
    $cv create line 24.004 136.14 20.575 132.46 -fill $col 
    $cv create line 20.575 132.46 17.146 128.11 -fill $col 
    $cv create line 17.146 128.11 13.717 123.09 -fill $col 
    $cv create line 13.717 123.09 10.287 117.41 -fill $col 
    $cv create line 10.287 117.41 6.858 111.05 -fill $col 
    $cv create line 6.858 111.05 3.429 104.03 -fill $col 
    $cv create line 3.429 104.03 0.0 96.333 -fill $col 
    $cv create line 0.0 96.333 0.0 86.7 -fill $col 
    $cv create line 345.2 96.333 0.0 96.333 -fill $col 
    $cv create line 0.0 86.7 0.0 52.075 -fill $col 
    $cv create line 325.2 81.7 337.77 81.634 -fill $col 
    $cv create line 337.77 81.634 350.33 81.438 -fill $col 
    $cv create line 350.33 81.438 362.9 81.109 -fill $col 
    $cv create line 362.9 81.109 375.47 80.65 -fill $col 
    $cv create line 375.47 80.65 388.03 80.059 -fill $col 
    $cv create line 388.03 80.059 400.6 79.338 -fill $col 
    $cv create line 400.6 79.338 413.17 78.484 -fill $col 
    $cv create line 413.17 78.484 425.73 77.5 -fill $col 
    $cv create line 425.73 77.5 438.3 76.384 -fill $col 
    $cv create line 438.3 76.384 450.87 75.138 -fill $col 
    $cv create line 450.87 75.138 463.43 73.759 -fill $col 
    $cv create line 463.43 73.759 476.0 72.25 -fill $col 
    $cv create line 325.2 81.7 0.0 81.7 -fill $col 
    $cv create line 0.0 52.075 41.15 52.075 -fill $col 
    $cv create line 124.8 52.075 351.2 52.075 -fill $col 
    $cv create line 434.85 52.075 476.0 52.075 -fill $col 
    $cv create line 0.0 47.075 36.15 47.075 -fill $col 
    $cv create line 128.8 47.075 346.2 47.075 -fill $col 
    $cv create line 438.85 47.075 476.0 47.075 -fill $col 
    $cv create line 41.15 31.9 42.575 42.725 -fill $col 
    $cv create line 42.575 42.725 46.753 52.812 -fill $col 
    $cv create line 46.753 52.812 53.4 61.475 -fill $col 
    $cv create line 53.4 61.475 62.062 68.122 -fill $col 
    $cv create line 62.062 68.122 72.15 72.3 -fill $col 
    $cv create line 72.15 72.3 82.975 73.725 -fill $col 
    $cv create line 82.975 73.725 93.8 72.3 -fill $col 
    $cv create line 93.8 72.3 103.89 68.122 -fill $col 
    $cv create line 103.89 68.122 112.55 61.475 -fill $col 
    $cv create line 112.55 61.475 119.2 52.813 -fill $col 
    $cv create line 119.2 52.813 123.38 42.725 -fill $col 
    $cv create line 123.38 42.725 124.8 31.9 -fill $col 
    $cv create line 351.2 31.9 352.62 42.725 -fill $col 
    $cv create line 352.62 42.725 356.8 52.813 -fill $col 
    $cv create line 356.8 52.813 363.45 61.475 -fill $col 
    $cv create line 363.45 61.475 372.11 68.122 -fill $col 
    $cv create line 372.11 68.122 382.2 72.3 -fill $col 
    $cv create line 382.2 72.3 393.02 73.725 -fill $col 
    $cv create line 393.02 73.725 403.85 72.3 -fill $col 
    $cv create line 403.85 72.3 413.94 68.122 -fill $col 
    $cv create line 413.94 68.122 422.6 61.475 -fill $col 
    $cv create line 422.6 61.475 429.25 52.813 -fill $col 
    $cv create line 429.25 52.813 433.43 42.725 -fill $col 
    $cv create line 433.43 42.725 434.85 31.9 -fill $col 
    $cv create line 25.0 101.33 167.6 101.33 -fill $col 
    $cv create line 167.6 101.33 167.6 139.5 -fill $col 
    $cv create line 167.6 139.5 46.15 139.5 -fill $col 
    $cv create line 46.15 139.5 44.387 139.24 -fill $col 
    $cv create line 44.387 139.24 42.625 138.44 -fill $col 
    $cv create line 42.625 138.44 40.862 137.12 -fill $col 
    $cv create line 40.862 137.12 39.1 135.26 -fill $col 
    $cv create line 39.1 135.26 37.337 132.87 -fill $col 
    $cv create line 37.337 132.87 35.575 129.96 -fill $col 
    $cv create line 35.575 129.96 33.812 126.51 -fill $col 
    $cv create line 33.812 126.51 32.05 122.54 -fill $col 
    $cv create line 32.05 122.54 30.287 118.03 -fill $col 
    $cv create line 30.287 118.03 28.525 113.0 -fill $col 
    $cv create line 28.525 113.0 26.762 107.43 -fill $col 
    $cv create line 26.762 107.43 25.0 101.33 -fill $col 
    $cv create line 177.6 101.33 325.2 101.33 -fill $col 
    $cv create line 238.0 139.5 245.27 139.24 -fill $col 
    $cv create line 245.27 139.24 252.53 138.44 -fill $col 
    $cv create line 252.53 138.44 259.8 137.12 -fill $col 
    $cv create line 259.8 137.12 267.07 135.26 -fill $col 
    $cv create line 267.07 135.26 274.33 132.87 -fill $col 
    $cv create line 274.33 132.87 281.6 129.96 -fill $col 
    $cv create line 281.6 129.96 288.87 126.51 -fill $col 
    $cv create line 288.87 126.51 296.13 122.54 -fill $col 
    $cv create line 296.13 122.54 303.4 118.03 -fill $col 
    $cv create line 303.4 118.03 310.67 113.0 -fill $col 
    $cv create line 310.67 113.0 317.93 107.43 -fill $col 
    $cv create line 317.93 107.43 325.2 101.33 -fill $col 
    $cv create line 238.0 139.5 177.6 139.5 -fill $col 
    $cv create line 177.6 139.5 177.6 101.33 -fill $col 
    $cv create line 172.6 31.9 172.6 144.5 -fill $col 
    $cv create line 325.2 31.9 325.2 101.33 -fill $col 
}
