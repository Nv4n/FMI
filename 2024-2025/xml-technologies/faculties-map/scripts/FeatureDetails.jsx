export default function FeatureDetails({ feature }) {
    return (
        <p>
            { feature.get('address') }
        </p>
    );
}
