float freqs[96] = {
    16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87,
    32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74,
    65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47,
    130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94,
    261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88,
    523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77,
    1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53,
    2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07
};

// const char notes[96] = {
//     "C0", "C#0", "D0", "D#0", "E0", "F0", "F#0", "G0", "G#0", "A0", "A#0", "B0",
//     "C1", "C#1", "D1", "D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
//     "C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
//     "C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
//     "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
//     "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5",
//     "C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6",
//     "C7", "C#7", "D7", "D#7", "E7", "F7", "F#7", "G7", "G#7", "A7", "A#7", "B7"
// };
//float A3_samples[128] = {0.000,0.984,0.348,-0.861,-0.652,0.631,0.875,-0.322,-0.989,-0.028,0.979,0.374,-0.847,-0.673,0.609,0.888,-0.295,-0.993,-0.055,0.973,0.399,-0.832,-0.693,0.587,0.901,-0.269,-0.996,-0.083,0.966,0.424,-0.816,-0.713,0.564,0.912,-0.242,-0.998,-0.111,0.959,0.449,-0.800,-0.732,0.541,0.923,-0.215,-0.999,-0.138,0.950,0.474,-0.783,-0.751,0.518,0.934,-0.188,-1.000,-0.165,0.941,0.498,-0.765,-0.769,0.494,0.943,-0.161,-1.000,-0.193,0.932,0.522,-0.747,-0.786,0.470,0.952,-0.133,-0.999,-0.220,0.921,0.545,-0.729,-0.803,0.445,0.960,-0.106,-0.997,-0.247,0.910,0.568,-0.709,-0.819,0.420,0.967,-0.078,-0.995,-0.274,0.898,0.591,-0.690,-0.835,0.395,0.974,-0.050,-0.992,-0.300,0.886,0.613,-0.669,-0.850,0.369,0.980,-0.023,-0.988,-0.326,0.873,0.635,-0.648,-0.864,0.343,0.985,0.005,-0.983,-0.352,0.859,0.656,-0.627,-0.877,0.317,0.990,0.033,-0.978,-0.378,0.844};
// uint32_t A3_samples_hex[128] = {0x0,0x3f7bf906,0x3eb212b9,0xbf5c82cf,0xbf26f4b3,0x3f21840b,0x3f60075c,0xbea4b4f9,0xbf7d2106,0xbce2eef8,0x3f7a9f83,0x3ebf4d7b,0xbf58d2ee,0xbf2c448d,0x3f1bf3a6,0x3f635fe4,0xbe9736dd,0xbf7e1749,0xbd62d8ac,0x3f7914c2,0x3ecc62a6,0xbf54f872,0xbf31728e,0x3f16449d,0x3f668bbf,0xbe899b0a,0xbf7edb9f,0xbdaa06a5,0x3f775910,0x3ed94fa8,0xbf50f41e,0xbf367db1,0x3f10780d,0x3f698a4d,0xbe77c85b,0xbf7f6de1,0xbde27f8b,0x3f756cc3,0x3ee611f8,0xbf4cc6bb,0xbf3b64f8,0x3f0a8f1a,0x3f6c5af7,0xbe5c29f2,0xbf7fcdf3,0xbe0d65f8,0x3f73503e,0x3ef2a712,0xbf48711c,0xbf40276e,0x3f048aed,0x3f6efd31,0xbe406047,0xbf7ffbc2,0xbe297062,0x3f7103e9,0x3eff0c7f,0xbf43f41a,0xbf44c421,0x3efcd96b,0x3f717075,0xbe2470cf,0xbf7ff744,0xbe455981,0x3f6e8839,0x3f059fe7,0xbf3f5097,0xbf493a2b,0x3ef06b4d,0x3f73b448,0xbe086107,0xbf7fc07b,0xbe611bd9,0x3f6bddaa,0x3f0b9f4d,0xbf3a877d,0xbf4d88ab,0x3ee3cdf1,0x3f75c839,0xbdd86ce6,0xbf7f5771,0xbe7cb1f6,0x3f6904c3,0x3f118344,0xbf3599bc,0xbf51aec8,0x3ed703d2,0x3f77abde,0xbd9fed38,0xbf7ebc3b,0xbe8c0b36,0x3f65fe13,0x3f174aa4,0xbf30884c,0xbf55abb2,0x3eca0f74,0x3f795ed9,0xbd4e9c3b,0xbf7deef7,0xbe99a1ec,0x3f62ca32,0x3f1cf449,0xbf2b542d,0xbf597ea0,0x3ebcf362,0x3f7ae0d5,0xbcba6ada,0xbf7cefcf,0xbea71a73,0x3f5f69c1,0x3f227f17,0xbf25fe63,0xbf5d26d2,0x3eafb22f,0x3f7c3185,0x3ba21d8c,0xbf7bbef3,0xbeb47224,0x3f5bdd6a,0x3f27e9f8,0xbf2087fc,0xbf60a38f,0x3ea24e77,0x3f7d50a7,0x3d05b8d5,0xbf7a5ca0,0xbec1a660,0x3f5825e0};

float A3_samples[512] = {0.0000000000,0.9807006305,-0.3834841611,-0.8307465086,0.7083316406,0.5537670141,-0.9248716042,-0.1921137223,0.9999939885,-0.1989147361,-0.9222121982,0.5595281182,0.7034194654,-0.8345868010,-0.3770703133,0.9820329107,-0.0069348104,-0.9793211862,0.3898795663,0.8268662639,-0.7132097505,-0.5479792781,0.9274865310,0.1853034694,-0.9999458966,0.2057061837,0.9195084411,-0.5652623135,-0.6984734613,0.8383869562,0.3706383314,-0.9833179628,0.0138692873,0.9778946442,-0.3962562213,-0.8229462534,0.7180535606,0.5421651885,-0.9300568530,-0.1784843047,0.9998497151,-0.2124877384,-0.9167604628,0.5709693240,0.6934938661,-0.8421467916,-0.3641885247,0.9845557251,-0.0208030971,-0.9764210732,0.4026138195,0.8189866656,-0.7228628380,-0.5363250251,0.9325824466,0.1716565564,-0.9997054487,0.2192590741,0.9139683956,-0.5766488754,-0.6884809192,0.8458661263,0.3577212034,-0.9857461379,0.0277359066,0.9749005439,-0.4089520551,-0.8149876909,0.7276373513,0.5304590687,-0.9350631902,-0.1648205528,0.9995131043,-0.2260198652,-0.9111323735,0.5823006945,0.6834348618,-0.8495447815,-0.3512366785,0.9868891441,-0.0346673821,-0.9733331296,0.4152706233,0.8109495217,-0.7323768710,-0.5245676013,0.9374989646,0.1579766225,-0.9992726911,0.2327697865,0.9082525332,-0.5879245094,-0.6783559365,0.8531825802,0.3447352618,-0.9879846886,0.0415971904,0.9717189056,-0.4215692203,-0.8068723522,0.7370811691,0.5186509063,-0.9398896527,-0.1511250949,0.9989842208,-0.2395085133,-0.9053290130,0.5935200498,0.6732443877,-0.8567793475,-0.3382172661,0.9890327188,-0.0485249982,-0.9700579495,0.4278475431,0.8027563785,-0.7417500193,-0.5127092682,0.9422351394,0.1442662993,-0.9986477071,0.2462357217,0.9023619536,-0.5990870466,-0.6681004610,0.8603349105,0.3316830048,-0.9900331842,0.0554504723,0.9683503412,-0.4341052898,-0.7986017984,0.7463831972,0.5067429729,-0.9445353119,-0.1374005656,0.9982631663,-0.2529510881,-0.8993514976,0.6046252319,0.6629244039,-0.8638490980,-0.3251327921,0.9909860368,-0.0623732797,-0.9665961628,0.4403421594,0.7944088119,-0.7509804799,-0.5007523072,0.9467900598,0.1305282240,-0.9978306168,0.2596542895,0.8962977899,-0.6101343395,-0.6577164654,0.8673217412,0.3185669431,-0.9918912307,0.0692930874,0.9647954987,-0.4465578520,-0.7901776205,0.7555416463,0.4947375592,-0.9489992744,-0.1236496050,0.9973500795,-0.2663450036,-0.8932009772,0.6156141044,0.6524768958,-0.8707526730,-0.3119857735,0.9927487225,-0.0762095627,-0.9629484355,0.4527520686,0.7859084277,-0.7600664770,-0.4886990182,0.9511628496,0.1167650395,-0.9968215774,0.2730229085,0.8900612086,-0.6210642631,-0.6472059472,0.8741417284,0.3053895999,-0.9935584707,0.0831223729,0.9610550620,-0.4589245114,-0.7816014390,0.7645547546,0.4826369746,-0.9532806813,-0.1098748585,0.9962451361,-0.2796876832,-0.8868786350,0.6264845535,0.6419038731,-0.8774887444,-0.2987787394,0.9943204366,-0.0900311855,-0.9591154693,0.4650748836,0.7772568612,-0.7690062630,-0.4765517200,0.9553526676,0.1029793933,-0.9956207831,0.2863390071,0.8836534095,-0.6318747149,-0.6365709284,0.8807935601,0.2921535099,-0.9950345835,0.0969356684,0.9571297506,-0.4712028893,-0.7728749036,0.7734207882,0.4704435469,-0.9573787090,-0.0960789757,0.9949485486,-0.2929765604,-0.8803856871,0.6372344880,0.6312073697,-0.8840560165,-0.2855142302,0.9957008770,-0.1038354894,-0.9550980015,0.4773082338,0.7684557766,-0.7777981179,-0.4643127492,0.9593587080,0.0891739374,-0.9942284649,0.2996000237,0.8770756251,-0.6425636151,-0.6258134548,0.8872759567,0.2788612195,-0.9963192850,0.1107303167,0.9530203197,-0.4833906235,-0.7639996930,0.7821380417,0.4581596217,-0.9612925693,-0.0822646105,0.9934605665,-0.3062090787,-0.8737233827,0.6478618400,0.6203894432,-0.8904532259,-0.2721947977,0.9968897779,-0.1176198188,-0.9508968050,0.4894497659,0.7595068670,-0.7864403507,-0.4519844603,0.9631801999,0.0753513274,-0.9926448904,0.3128034074,0.8703291210,-0.6531289078,-0.6149355957,0.8935876713,0.2655152855,-0.9974123282,0.1245036643,0.9487275597,-0.4954853696,-0.7549775146,0.7907048381,0.4457875620,-0.9650215092,-0.0684344204,0.9917814759,-0.3193826927,-0.8668930032,0.6583645652,0.6094521746,-0.8966791421,-0.2588230041,0.9978869108,-0.1313815221,-0.9465126879,0.5014971444,0.7504118538,-0.7949312988,-0.4395692248,0.9668164084,0.0615142223,-0.9908703645,0.3259466181,0.8634151947,-0.6635685604,-0.6039394436,0.8997274897,0.2521182753,-0.9983135029,0.1382530615,0.9442522963,-0.5074848010,-0.7458101040,0.7991195295,0.4333297477,-0.9685648114,-0.0545910658,0.9899116000,-0.3324948681,-0.8598958627,0.6687406431,0.5983976679,-0.9027325674,-0.2454014216,0.9986920838,-0.1451179521,-0.9419464936,0.5134480516,0.7411724865,-0.8032693288,-0.4270694309,0.9702666339,0.0476652839,-0.9889052285,0.3390271277,0.8563351764,-0.6738805647,-0.5928271139,0.9056942307,0.2386727660,-0.9990226355,0.1519758635,0.9395953906,-0.5193866094,-0.7364992245,0.8073804971,0.4207885754,-0.9719217942,-0.0407372097,0.9878512983,-0.3455430828,-0.8527333071,0.6789880778,0.5872280496,-0.9086123372,-0.2319326321,0.9993051420,-0.1588264662,-0.9371991005,0.5253001888,0.7317905426,-0.8114528368,-0.4144874832,0.9735302127,0.0338071764,-0.9867498603,0.3520424199,0.8490904280,-0.6840629370,-0.5816007442,0.9114867466,0.2251813441,-0.9995395898,0.1656694305,0.9347577384,-0.5311885053,-0.7270466673,0.8154861519,0.4081664575,-0.9750918120,-0.0268755172,0.9856009673,-0.3585248266,-0.8454067143,0.6891048981,0.5759454683,-0.9143173206,-0.2184192266,0.9997259676,-0.1725044274,-0.9322714217,0.5370512758,0.7222678268,-0.8194802485,-0.4018258021,0.9766065171,0.0199425655,-0.9844046746,0.3649899910,0.8416823431,-0.6941137186,-0.5702624940,0.9171039231,0.2116466049,-0.9998642663,0.1793311282,0.9297402701,-0.5428882183,-0.7174542508,0.8234349346,0.3954658221,-0.9780742550,-0.0130086547,0.9831610398,-0.3714376022,-0.8379174936,0.6990891577,0.5645520946,-0.9198464201,-0.2048638046,0.9999544794,-0.1861492046,-0.9271644053,0.5486990522,0.7126061709,-0.8273500198,-0.3890868232,0.9794949552,0.0060741183,-0.9818701226,0.3778673502,0.8341123468,-0.7040309761,-0.5588145446,0.9225446797,0.1980711520,-0.9999966025,0.1929583286,0.9245439511,-0.5544834980,-0.7077238202,0.8312253161,0.3826891123,-0.9808685493,0.0008607102,0.9805319851,-0.3842789257,-0.8302670858,0.7089389361,0.5530501200,-0.9251985721,-0.1912689737,0.9999906336,-0.1997581729,-0.9218790336,0.5602412774,0.7028074336,-0.8350606368,-0.3762729971,0.9821949713,-0.0077954973,-0.9791466917,0.3906720205,0.8263818954,-0.7138128017,-0.5472590980,0.9278079696,0.1844575969,-0.9999365730,0.2065484104,0.9191697809,-0.5659721136,-0.6978572474,0.8388557977,0.3698387860,-0.9834741575,0.0147299096,0.9777143090,-0.3970463269,-0.8224569625,0.7186523385,0.5414417571,-0.9303727469,-0.1776373490,0.9998344232,-0.2133287145,-0.9164163234,0.5716757310,0.6928734997,-0.8426106162,-0.3633867887,0.9847060462,-0.0216636134,-0.9762349060,0.4034015386,0.8184924759,-0.7234573137,-0.5355983771,0.9328927805,0.1708085583,-0.9996841893};

//float Asharp3_samples[128] = {0.000,0.995,0.189,-0.959,-0.372,0.889,0.541,-0.786,-0.691,0.654,0.815,-0.499,-0.910,0.326,0.972,-0.141,-0.999,-0.049,0.990,0.237,-0.944,-0.417,0.865,0.582,-0.754,-0.725,0.616,0.843,-0.456,-0.929,0.279,0.982,-0.092,-1.000,-0.098,0.981,0.285,-0.927,-0.461,0.839,0.621,-0.721,-0.758,0.577,0.868,-0.412,-0.946,0.232,0.990,-0.043,-0.999,-0.147,0.971,0.331,-0.908,-0.504,0.812,0.659,-0.686,-0.789,0.536,0.891,-0.367,-0.961,0.184,0.996,0.006,-0.995,-0.195,0.958,0.377,-0.886,-0.546,0.782,0.695,-0.650,-0.818,0.494,0.912,-0.321,-0.973,0.135,0.999,0.055,-0.989,-0.243,0.943,0.422,-0.862,-0.586,0.751,0.729,-0.612,-0.846,0.451,0.931,-0.274,-0.983,0.087,1.000,0.104,-0.980,-0.290,0.925,0.466,-0.836,-0.625,0.717,0.762,-0.572,-0.871,0.407,0.948,-0.226,-0.991,0.038,0.998,0.152,-0.969,-0.337,0.905,0.509,-0.808,-0.663,0.682,0.793,-0.531,-0.894};
uint32_t Asharp3_samples_hex[128] = {0x0,0x3f7ed6b5,0x3e41f7d8,0xbf759c83,0xbebe74dd,0x3f637da8,0x3f0a8432,0xbf49221c,0xbf30ca00,0x3f277e2e,0x3f50a916,0xbeff9366,0xbf68fa04,0x3ea6e969,0x3f78db68,0xbe106883,0xbf7fba0c,0xbd48f178,0x3f7d5643,0x3e730f98,0xbf71c634,0xbed58ae6,0x3f5d750d,0x3f14e94c,0xbf411f22,0xbf39a8d6,0x3f1dcb19,0x3f57af6d,0xbee980d7,0xbf6de6c0,0x3e8ef70f,0x3f7b80e1,0xbdbd004f,0xbf7fffbb,0xbdc8b388,0x3f7b39a2,0x3e91c8c0,0xbf6d5ad7,0xbeec1d4a,0x3f56e3eb,0x3f1ef299,0xbf38a51a,0xbf421536,0x3f13b6bd,0x3f5e30cc,0xbed2de55,0xbf7240d1,0x3e6d5923,0x3f7d8b4d,0xbd317627,0xbf7fa798,0xbe16394c,0x3f788221,0x3ea9afd4,0xbf685d27,0xbf010f0f,0x3f4fce4f,0x3f2899e9,0xbf2fb93c,0xbf4a09ef,0x3f094751,0x3f642930,0xbebbb9d3,0xbf760589,0x3e3c31d5,0x3f7ef96a,0x3bbc0dba,0xbf7eb1d9,0xbe47bc38,0x3f75316c,0x3ec12e4b,0xbf62d036,0xbf0bbfe8,0x3f483896,0x3f31d947,0xbf26610a,0xbf51821a,0x3efd0686,0x3f6994eb,0xbea42196,0xbf793295,0x3e0a9682,0x3f7fca57,0x3d606b18,0xbf7d1f16,0xbe78c400,0x3f71498e,0x3ed835aa,0xbf5cb771,0xbf161a9a,0x3f40276e,0x3f3aab01,0xbf1ca245,0xbf58791c,0x3ee6e26d,0x3f6e70a6,0xbe8c2429,0xbf7bc600,0x3db14b7f,0x3f7ffd92,0x3dd4650f,0xbf7af046,0xbe949936,0x3f6cccef,0x3eeeb7bf,0xbf56169a,0xbf2018c2,0x3f379fcf,0x3f4309a6,0xbf1282f0,0xbf5eeaaa,0x3ed02ffd,0x3f72b962,0xbe67a0ad,0xbf7dbe34,0x3d19f957,0x3f7f92fd,0x3e1c08d1,0xbf7826c3,0xbeac74d0,0x3f67be54,0x3f025354,0xbf4ef1c7,0xbf29b437,0x3f2ea6fd,0x3f4af00e,0xbf080948,0xbf64d2cb};

//float B3_samples[128] = {0.000,1.000,0.013,-1.000,-0.027,0.999,0.040,-0.999,-0.053,0.998,0.066,-0.997,-0.079,0.996,0.093,-0.995,-0.106,0.994,0.119,-0.992,-0.132,0.990,0.145,-0.988,-0.158,0.986,0.172,-0.984,-0.185,0.982,0.198,-0.979,-0.211,0.976,0.223,-0.973,-0.236,0.970,0.249,-0.967,-0.262,0.963,0.275,-0.960,-0.288,0.956,0.300,-0.952,-0.313,0.948,0.325,-0.943,-0.338,0.939,0.350,-0.934,-0.363,0.929,0.375,-0.924,-0.387,0.919,0.400,-0.914,-0.412,0.909,0.424,-0.903,-0.436,0.897,0.448,-0.891,-0.459,0.885,0.471,-0.879,-0.483,0.873,0.494,-0.866,-0.506,0.859,0.517,-0.852,-0.529,0.845,0.540,-0.838,-0.551,0.831,0.562,-0.823,-0.573,0.816,0.584,-0.808,-0.594,0.800,0.605,-0.792,-0.615,0.784,0.626,-0.776,-0.636,0.767,0.646,-0.759,-0.656,0.750,0.666,-0.741,-0.676,0.732,0.686,-0.723,-0.695,0.714,0.705,-0.705,-0.714,0.695,0.723,-0.686,-0.733,0.676,0.742,-0.666};
uint32_t B3_samples_hex[128] = {0x0,0x3f7ffe8f,0x3c593aab,0xbf7ff30a,0xbcd935c8,0x3f7fdc00,0x3d22e23a,0xbf7fb972,0xbd59223b,0x3f7f8b62,0x3d87ac3b,0xbf7f51d1,0xbda2c13e,0x3f7f0cc3,0x3dbdceee,0xbf7ebc3b,0xbdd8d413,0x3f7e603c,0x3df3cf75,0xbf7df8ca,0xbe075fef,0x3f7d85ea,0x3e14d20d,0xbf7d07a1,0xbe223d77,0x3f7c7df5,0x3e2fa195,0xbf7be8ec,0xbe3cfdcb,0x3f7b488c,0x3e4a517f,0xbf7a9cde,0xbe579c19,0x3f79e5e8,0x3e64dcfe,0xbf7923b3,0xbe721397,0x3f785648,0x3e7f3f4b,0xbf777db0,0xbe862fc1,0x3f7699f4,0x3e8cb9d2,0xbf75ab1f,0xbe933d8f,0x3f74b13c,0x3e99baab,0xbf73ac56,0xbea030db,0x3f729c78,0x3ea69fd6,0xbf7181af,0xbead0752,0x3f705c07,0x3eb36704,0xbf6f2b8f,0xbeb9bea3,0x3f6df053,0x3ec00de6,0xbf6caa61,0xbec65484,0x3f6b59c9,0x3ecc9235,0xbf69fe9a,0xbed2c6b2,0x3f6898e2,0x3ed8f1b2,0xbf6728b3,0xbedf12ef,0x3f65ae1c,0x3ee52a21,0xbf642930,0xbeeb3703,0x3f6299fe,0x3ef13950,0xbf61009a,0xbef730c1,0x3f5f5d16,0x3efd1d12,0xbf5daf84,0xbf017f00,0x3f5bf7f9,0x3f0469a2,0xbf5a3687,0xbf074e4f,0x3f586b42,0x3f0a2ce6,0xbf569641,0xbf0d0544,0x3f54b797,0x3f0fd749,0xbf52cf5b,0xbf12a2d6,0x3f50dda1,0x3f1567c9,0xbf4ee281,0xbf182602,0x3f4cde12,0x3f1add63,0xbf4ad06b,0xbf1d8dcb,0x3f48b9a2,0x3f20371d,0xbf4699d2,0xbf22d938,0x3f447111,0x3f2573ff,0xbf423f79,0xbf280754,0x3f400523,0x3f2a9319,0xbf3dc228,0xbf2d1731,0x3f3b76a4,0x3f2f937f,0xbf3922af,0xbf3207e6,0x3f36c666,0x3f347449,0xbf3461e3,0xbf36d88e,0x3f31f541,0x3f393498,0xbf2f809e,0xbf3b884d,0x3f2d0414,0x3f3dd390,0xbf2a7fc1};

// float C4_samples[100] = {};