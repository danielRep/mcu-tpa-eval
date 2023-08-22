import matplotlib.pyplot as plt
import numpy as np

# Data
#mbb_hit = list(range(1, 22))
#standalone = [221, 992, 1752, 14882, 16503, 17898, 19338, 19753, 20718, 21323, 22858, 22943, 49178, 49238, 78671, 163126, 165761, 2367332, 2414829, 2416390, 2416660]
#set_point = [287.3, 1289.6, 2277.6, 19346.6, 21453.9, 23267.4, 25139.4, 25678.9, 26933.4, 27719.9, 29715.4, 29825.9, 63931.4, 64009.4, 102272.3, 212063.8, 215489.3, 3077531.6, 3139277.7, 3141307, 3141658]
#co_runner = [1220, 5450, 9210, 55375, 59535, 64530, 69570, 70945, 74190, 76555, 82275, 82720, 177890, 178230, 326450, 582745, 589965, 7390520, 7521530, 7527910, 7529420]
#regulation = [1299, 5815, 7887, 22329, 25322, 28064, 30911, 32703, 35045, 37052, 39989, 41476, 69113, 70575, 101410, 372991, 379431, 2582349, 2728490, 2738535, 2743975]
#cpu_status = ['PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'RUNNING', 'PAUSED', 'PAUSED', 'RUNNING', 'RUNNING', 'RUNNING', 'RUNNING']

#mbb_hit = list(range(1, 14))
#standalone = [1627, 14757, 17673, 20378, 22498, 48269, 77702, 162157, 2367303, 2414800, 2416361, 2416546, 2416696]
#set_point = [2115.1, 19184.1, 22974.9, 26491.4, 29247.4, 62749.7, 101012.6, 210804.1, 3077493.9, 3139240, 3141269.3, 3141509.8, 3141704.8]
#co_runner = [8445, 49545, 58000, 66850, 74930, 167710, 315675, 585620, 8067640, 8212260, 8218695, 8219720, 8220510]
#regulation = [8524, 25494, 29782, 33864, 37386, 64559, 95369, 367790, 2576741, 2726267, 2736752, 2741842, 2746697]
#cpu_status = ['PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'RUNNING', 'PAUSED', 'RUNNING', 'RUNNING', 'RUNNING', 'RUNNING', 'RUNNING']

#mbb_hit = list(range(1, 14))
#standalone = [1627, 14757, 17673, 20378, 22498, 48269, 77702, 162157, 2367303, 2414800, 2416361, 2416546, 2416696]
#set_point = [1675.81, 15199.71, 18203.19, 20989.34, 23172.94, 49717.07, 80033.06, 167021.71, 2438322.09, 2487244, 2488851.83, 2489042.38, 2489196.88]
#co_runner = [8445, 49545, 58000, 66850, 74930, 167710, 315675, 585620, 8067640, 8212260, 8218695, 8219720, 8220510]
#regulation = [9364, 25674, 29717, 33524, 36826, 63779, 94369, 179981, 2386284, 2434928, 2437636, 2438968, 2440265]
#cpu_status = ['PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED', 'PAUSED']

mbb_hit = list(range(1, 6))
standalone = [120, 358515, 456530, 814950, 1172182]
set_point = [156, 466069.5, 593489, 1059435, 1523836.6]
co_runner = [640, 905240, 1163790, 2060670, 2984500]
regulation = [599.0, 362794.0, 620670.0, 982910.0, 1341519.0]
cpu_status = ['PAUSED', 'RUNNING', 'PAUSED', 'PAUSED', 'PAUSED']


# Create the line chart
plt.semilogx(standalone,mbb_hit,  label='standalone', marker='s')
plt.semilogx(set_point,mbb_hit,  label='set-point', marker='x')
plt.semilogx(co_runner,mbb_hit,  label='w/ co-runner', marker='.')
plt.semilogx(regulation,mbb_hit,  label='w/ regulation', marker='v')

# Plot "w/ regulation" line with color-coded markers
for i in range(1, len(regulation)-1):
    #if cpu_status[i] != cpu_status[i-1] or cpu_status[i] != cpu_status[i+1]:
        marker = 'o' if cpu_status[i] == 'RUNNING' else 'o'
        marker_color = 'green' if cpu_status[i] == 'RUNNING' else 'black'
        plt.plot(regulation[i], mbb_hit[i], marker=marker, color=marker_color, markersize=4)

# Set axis labels and chart title
plt.xlabel('Time (cycles)')
plt.ylabel('MBB Hit')
plt.title('Execution Progress')

# Display legend
plt.legend()

# Show the chart
plt.show()