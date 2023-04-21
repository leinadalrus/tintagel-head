mod usage_config_router;

use anyhow::Result;

#[tokio::test]
async fn manager_runs_build_dev() -> Result<()> {
    let httpc_tester = httpc_test::new_client("http://localhost:8080")?;
    httpc_tester.do_get("/").await?.print().await?;
    return Ok(());
}