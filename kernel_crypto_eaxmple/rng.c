/*
 * +------------------+
 * |     init tfm     |
 * | crypto_alloc_rng |
 * +------------------+
 *
 *
 * +------------------+
 * |                  |
 * |                  |
 * +------------------+
 */


static int get_random_numbers(u8 *buf, unsigned int len)
{
    // 初始化结构体用以承载tfm
    struct crypto_rng *rng = NULL;
    // 定义RNG算法类型  查找算法种类 grep "\.alg = \"" -nr .
    char *drbg = "drbg_nopr_sha256"; /* Hash DRBG with SHA-256, no PR */
    int ret;

    if (!buf || !len) {
        pr_debug("No output buffer provided\n");
        return -EINVAL;
    }

    //实例化tfm
    rng = crypto_alloc_rng(drbg, 0, 0);
    if (IS_ERR(rng)) {
        pr_debug("could not allocate RNG handle for %s\n", drbg);
        return PTR_ERR(rng);
    }

    //crypto_rng类中有直接定义好的 *generate方法
    ret = crypto_rng_get_bytes(rng, buf, len);
    if (ret < 0)
        pr_debug("generation of random numbers failed\n");
    else if (ret == 0)
        pr_debug("RNG returned no data");
    else
        pr_debug("RNG returned %d bytes of data\n", ret);

out:
    crypto_free_rng(rng);
    return ret;
}