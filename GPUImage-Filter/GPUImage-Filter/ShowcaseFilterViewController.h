#import <UIKit/UIKit.h>
#import "GPUImage.h"

typedef enum {
    GPUIMAGE_SATURATION,//饱和度
    GPUIMAGE_CONTRAST, //对比度
    GPUIMAGE_BRIGHTNESS, //亮度
    GPUIMAGE_LEVELS,//色阶
    GPUIMAGE_EXPOSURE,//曝光
    GPUIMAGE_RGB, //RGB
    GPUIMAGE_HUE, //色度
    GPUIMAGE_WHITEBALANCE,//白平横
    GPUIMAGE_MONOCHROME, //单色
    GPUIMAGE_FALSECOLOR,//色彩替换（替换亮部和暗部色彩）
    GPUIMAGE_SHARPEN,//锐化
    GPUIMAGE_UNSHARPMASK, //反遮罩锐化
    GPUIMAGE_TRANSFORM, //形状变化
    GPUIMAGE_TRANSFORM3D,
    GPUIMAGE_CROP, //剪裁
    GPUIMAGE_MASK,//遮罩混合
    GPUIMAGE_GAMMA, //伽马线
    GPUIMAGE_TONECURVE,//色调曲线
    GPUIMAGE_HIGHLIGHTSHADOW,//提亮阴影
    GPUIMAGE_HAZE, //朦胧加暗
    GPUIMAGE_SEPIA, //褐色（怀旧）
    GPUIMAGE_AMATORKA,//Amatorka lookup
    GPUIMAGE_MISSETIKATE,//MissEtikate lookup
    GPUIMAGE_SOFTELEGANCE,//SoftElegance
    GPUIMAGE_COLORINVERT,//反色
    GPUIMAGE_GRAYSCALE,//灰度
    GPUIMAGE_HISTOGRAM,//色彩直方图，显示在图片上
    GPUIMAGE_HISTOGRAM_EQUALIZATION, //色彩直方图
    GPUIMAGE_AVERAGECOLOR, //像素平均色值
    GPUIMAGE_LUMINOSITY,//亮度平均
    GPUIMAGE_THRESHOLD,
    GPUIMAGE_ADAPTIVETHRESHOLD,
    GPUIMAGE_AVERAGELUMINANCETHRESHOLD,//像素色值亮度平均，图像黑白（有类似漫画效果）
    GPUIMAGE_PIXELLATE,//像素化
    GPUIMAGE_POLARPIXELLATE,
    GPUIMAGE_PIXELLATE_POSITION,
    GPUIMAGE_POLKADOT, //像素圆点花样
    GPUIMAGE_HALFTONE,//点染,图像黑白化，由黑点构成原图的大致图形
    GPUIMAGE_CROSSHATCH,//交叉线阴影，形成黑白网状画面
    GPUIMAGE_SOBELEDGEDETECTION, //Sobel边缘检测算法(白边，黑内容，有点漫画的反色效果)
    GPUIMAGE_PREWITTEDGEDETECTION,//普瑞维特(Prewitt)边缘检测(效果与Sobel差不多，貌似更平滑)
    GPUIMAGE_CANNYEDGEDETECTION,//Canny边缘检测算法（比上更强烈的黑白对比度）
    GPUIMAGE_THRESHOLDEDGEDETECTION,//阈值边缘检测（效果与上差别不大）
    GPUIMAGE_XYGRADIENT,
    GPUIMAGE_HARRISCORNERDETECTION,//Harris角点检测，会有绿色小十字显示在图片角点处
    GPUIMAGE_NOBLECORNERDETECTION,//Noble角点检测，检测点更多
    GPUIMAGE_SHITOMASIFEATUREDETECTION,//ShiTomasi角点检测，与上差别不大
    GPUIMAGE_HOUGHTRANSFORMLINEDETECTOR, //线条检测
    GPUIMAGE_BUFFER,
    GPUIMAGE_LOWPASS, //用于图像加亮
    GPUIMAGE_HIGHPASS,//图像低于某值时显示为黑
    GPUIMAGE_MOTIONDETECTOR,
    GPUIMAGE_SKETCH, //素描
    GPUIMAGE_THRESHOLDSKETCH,//阀值素描，形成有噪点的素描
    GPUIMAGE_TOON, //卡通效果（黑色粗线描边）
    GPUIMAGE_SMOOTHTOON, //相比上面的效果更细腻，上面是粗旷的画风
    GPUIMAGE_TILTSHIFT,//条纹模糊，中间清晰，上下两端模糊
    GPUIMAGE_CGA, //CGA色彩滤镜，形成黑、浅蓝、紫色块的画面
    GPUIMAGE_POSTERIZE, //色调分离，形成噪点效果
    GPUIMAGE_CONVOLUTION,
    GPUIMAGE_EMBOSS,//浮雕效果，带有点3d的感觉
    GPUIMAGE_LAPLACIAN,
    GPUIMAGE_CHROMAKEYNONBLEND,//色度键混合
    GPUIMAGE_KUWAHARA,//桑原(Kuwahara)滤波,水粉画的模糊效果；处理时间比较长，慎用
    GPUIMAGE_KUWAHARARADIUS3,
    GPUIMAGE_VIGNETTE,//晕影，形成黑色圆形边缘，突出中间图像的效果
    GPUIMAGE_GAUSSIAN,//高斯模糊
    GPUIMAGE_GAUSSIAN_SELECTIVE,//高斯模糊，选择部分清晰
    GPUIMAGE_GAUSSIAN_POSITION,
    GPUIMAGE_BOXBLUR,//盒状模糊
    GPUIMAGE_MEDIAN, //中间值，有种稍微模糊边缘的效果
    GPUIMAGE_BILATERAL,//双边模糊
    GPUIMAGE_MOTIONBLUR,
    GPUIMAGE_ZOOMBLUR,
    GPUIMAGE_IOSBLUR,
    GPUIMAGE_SWIRL,//漩涡，中间形成卷曲的画面
    GPUIMAGE_BULGE, //凸起失真，鱼眼效果
    GPUIMAGE_PINCH, //收缩失真，凹面镜
    GPUIMAGE_SPHEREREFRACTION,//球形折射，图形倒立
    GPUIMAGE_GLASSSPHERE,//水晶球效果
    GPUIMAGE_STRETCH,//伸展失真，哈哈镜
    GPUIMAGE_DILATION,//扩展边缘模糊，变黑白
    GPUIMAGE_EROSION,//侵蚀边缘模糊，变黑白
    GPUIMAGE_OPENING, //黑白色调模糊
    GPUIMAGE_CLOSING,//黑白色调模糊，暗色会被提亮
    GPUIMAGE_PERLINNOISE,//柏林噪点，花边噪点
    GPUIMAGE_VORONOI,
    GPUIMAGE_MOSAIC, //黑白马赛克
    GPUIMAGE_LOCALBINARYPATTERN, //图像黑白化，并有大量噪点
    GPUIMAGE_DISSOLVE,//溶解
    GPUIMAGE_CHROMAKEY,  //色度键混合
    GPUIMAGE_ADD, //通常用于创建两个图像之间的动画变亮模糊效果
    GPUIMAGE_DIVIDE,//通常用于创建两个图像之间的动画变暗模糊效果
    GPUIMAGE_MULTIPLY,//通常用于创建阴影和深度效果
    GPUIMAGE_OVERLAY, //叠加,通常用于创建阴影效果
    GPUIMAGE_LIGHTEN, //减淡混合,通常用于重叠类型
    GPUIMAGE_DARKEN, //加深混合,通常用于重叠类型
    GPUIMAGE_COLORBURN,//色彩加深混合
    GPUIMAGE_COLORDODGE, //色彩减淡混合
    GPUIMAGE_LINEARBURN,
    GPUIMAGE_SCREENBLEND,//屏幕包裹,通常用于创建亮点和镜头眩光
    GPUIMAGE_DIFFERENCEBLEND, //差异混合,通常用于创建更多变动的颜色
    GPUIMAGE_SUBTRACTBLEND, //差值混合,通常用于创建两个图像之间的动画变暗模糊效
    GPUIMAGE_EXCLUSIONBLEND,//排除混合
    GPUIMAGE_HARDLIGHTBLEND, //强光混合,通常用于创建阴影效果
    GPUIMAGE_SOFTLIGHTBLEND,//柔光混合
    GPUIMAGE_COLORBLEND,
    GPUIMAGE_HUEBLEND,
    GPUIMAGE_SATURATIONBLEND,
    GPUIMAGE_LUMINOSITYBLEND,
    GPUIMAGE_NORMALBLEND, //正常
    GPUIMAGE_POISSONBLEND,
    GPUIMAGE_OPACITY, //不透明度
    GPUIMAGE_CUSTOM,
    GPUIMAGE_UIELEMENT,
    GPUIMAGE_FILECONFIG,
    GPUIMAGE_FILTERGROUP,
    GPUIMAGE_FACES,
    GPUIMAGE_NUMFILTERS
} GPUImageShowcaseFilterType; 


@interface ShowcaseFilterViewController : UIViewController <GPUImageVideoCameraDelegate>
{
    GPUImageVideoCamera *videoCamera;
    GPUImageOutput<GPUImageInput> *filter;
    GPUImagePicture *sourcePicture;
    GPUImageShowcaseFilterType filterType;
    GPUImageUIElement *uiElementInput;
    
    GPUImageFilterPipeline *pipeline;
    UIView *faceView;
    
    CIDetector *faceDetector;
    
    IBOutlet UISwitch *facesSwitch;
    IBOutlet UILabel *facesLabel;
    __unsafe_unretained UISlider *_filterSettingsSlider;
    BOOL faceThinking;
}

@property(readwrite, unsafe_unretained, nonatomic) IBOutlet UISlider *filterSettingsSlider;
@property(nonatomic,retain) CIDetector*faceDetector;
// Initialization and teardown
- (id)initWithFilterType:(GPUImageShowcaseFilterType)newFilterType;
- (void)setupFilter;
- (void)willOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;
// Filter adjustments
- (IBAction)updateFilterFromSlider:(id)sender;
- (void)GPUVCWillOutputFeatures:(NSArray*)featureArray forClap:(CGRect)clap
                 andOrientation:(UIDeviceOrientation)curDeviceOrientation;
-(IBAction)facesSwitched:(id)sender;
@end
