#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <chrono>
#include <iostream>

class Benchmark
{
public:
    Benchmark(void) = delete;

    Benchmark(const char* const benchmark_name) : benchmark_name(benchmark_name)
    {
        start_time_point = std::chrono::high_resolution_clock::now();
    }
    ~Benchmark(void)
    {
        Stop();
    }

    void Stop()
    {
        std::chrono::_V2::system_clock::time_point end_time_point = std::chrono::high_resolution_clock::now();

        std::chrono::microseconds::rep start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time_point).time_since_epoch().count();
        std::chrono::microseconds::rep end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();

        int64_t duration = end - start;

        std::cout << benchmark_name << ": ";
        std::cout << duration << "us\n";
    }

private:
    std::chrono::_V2::system_clock::time_point start_time_point;
    const char* const benchmark_name; 
};

//TEST FUNCSstd::chrono::high_resolution_clock::now()
double loge_d(double number, double base);
double log10_d(double number, double base);
double log2_d(double number, double base);

float loge_f(float number, float base);
float log10_f(float number, float base);
float log2_f(float number, float base);

float loge_u(uint32_t number, uint32_t base);
float log10_u(uint32_t number, uint32_t base);
float log2_u(uint32_t number, uint32_t base);

int main(int argc, char* argv[])
{
    typedef uint32_t rand_pair[2];

    const long max_iterations = std::atol(argv[1]);
    rand_pair *rand_values = new rand_pair[max_iterations];

    srand(time(NULL));
    for (uint64_t i = 0; i < max_iterations; i++)
    {
        rand_values[i][0] = rand();
        rand_values[i][1] = rand();
    }

    {

        double (*funcs[])(double, double) = {loge_d, log10_d, log2_d};
        const char* func_names[] = {"loge_d", "log10_d", "log2_d"};
        const std::uint64_t number_of_funcs = sizeof(func_names)/sizeof(const char*);

        for (std::uint64_t func_num = 0; func_num < number_of_funcs; func_num++)
        {
            Benchmark bench(func_names[func_num]);
            for (std::uint64_t i = 0; i < max_iterations; i++)
            {
                funcs[func_num](rand(), rand());
            }
        }
    }

    std::cout << "\n";

    {
        float (*funcs[])(float, float) = {loge_f, log10_f, log2_f};
        const char* func_names[] = {"loge_f", "log10_f", "log2_f"};
        const std::uint64_t number_of_funcs = sizeof(func_names)/sizeof(const char*);

        for (std::uint64_t func_num = 0; func_num < number_of_funcs; func_num++)
        {
            Benchmark bench(func_names[func_num]);
            for (std::uint64_t i = 0; i < max_iterations; i++)
            {
                funcs[func_num](rand_values[i][0], rand_values[i][1]);
            }
        }
    }

    std::cout << "\n";

    {
        float (*funcs[])(uint32_t, uint32_t) = {loge_u, log10_u, log2_u};
        const char* func_names[] = {"loge_u", "log10_u", "log2_u"};
        const std::uint64_t number_of_funcs = sizeof(func_names)/sizeof(const char*);

        for (std::uint64_t func_num = 0; func_num < number_of_funcs; func_num++)
        {
            Benchmark bench(func_names[func_num]);
            for (std::uint64_t i = 0; i < max_iterations; i++)
            {
                funcs[func_num](rand_values[i][0], rand_values[i][1]);
            }
        }
    }

    delete [] rand_values;
}

double loge_d(double number, double base)
{
    return std::log(number)/std::log(base);
}
//EOF

double log10_d(double number, double base)
{
    return std::log10(number)/std::log10(base);
}
//EOF

double log2_d(double number, double base)
{
    return std::log2(number)/std::log2(base);
}
//EOF


float loge_f(float number, float base)
{
    return std::log(number)/std::log(base);
}
//EOF

float log10_f(float number, float base)
{
    return std::log10(number)/std::log10(base);
}
//EOF

float log2_f(float number, float base)
{
    return std::log2(number)/std::log2(base);
}
//EOF

float loge_u(uint32_t number, uint32_t base)
{
    return std::log(number)/std::log(base);
}
//EOF

float log10_u(uint32_t number, uint32_t base)
{
    return std::log10(number)/std::log10(base);
}
//EOF

float log2_u(uint32_t number, uint32_t base)
{
    return std::log2(number)/std::log2(base);
}
//EOF
